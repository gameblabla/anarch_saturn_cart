PRGNAME     = installer.elf
CC			= /opt/saturn/bin/sh-elf-gcc 

SRCDIR		= ./src ./assets iapetus/src ./src/crt
SRCDIR		+= iapetus/src/ar iapetus/src/cd iapetus/src/file iapetus/src/modem iapetus/src/peripherals iapetus/src/scu iapetus/src/sh2 iapetus/src/ui iapetus/src/video
VPATH		= $(SRCDIR)
SRC_C		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
SRC_CP		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cpp))
SRC_S		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.s))
OBJ_C		= $(notdir $(patsubst %.c, %.o, $(SRC_C)))
OBJ_CP		= $(notdir $(patsubst %.cpp, %.o, $(SRC_CP)))
OBJ_S		= $(notdir $(patsubst %.s, %.o, $(SRC_S)))


SRC_PAL		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.pal))
C_PAL		= $(notdir $(patsubst %.pal, %.c, $(SRC_PAL)))
OBJ_PAL		= $(notdir $(patsubst %.pal, %.o, $(SRC_PAL))) 

OBJS		= $(OBJ_C) $(OBJ_CP) $(OBJ_PAL)

CFLAGS		= -Ofast -m2 -mno-ieee -mbitops -mfmovd -fno-PIC -flto -Isrc/inc
CFLAGS		+= -Isource 
CFLAGS		+= -Iinclude
CFLAGS		+= -DMISSING_SYSCALL_NAMES -DREENTRANT_SYSCALLS_PROVIDED 

LDFLAGS     = -no-pie -Wl,--as-needed -Wl,--gc-sections -s -flto

all: convert_pal samples $(OBJ_C) $(OBJ_S) $(PRGNAME)

# Rules to make executable
$(PRGNAME): $(OBJS)
	$(CC) $(CFLAGS) -Wall -nostartfiles -Wl,--script,src/bart.lk $(OBJ_S) $^ -o $(PRGNAME) 
	/opt/saturn/bin/sh-elf-objcopy --output-format=binary $(PRGNAME) anarch_cartridge_saturn.bin

ADP_OBJ=explosion-4bit.adp click-4bit.adp monster-4bit.adp

samples:
		./scspadpcm/adpencode 0 snds/explosion.wav explosion-4bit.adp
		./scspadpcm/adpencode 0 snds/click.wav click-4bit.adp
		./scspadpcm/adpencode 0 snds/monster.wav monster-4bit.adp
		./scspadpcm/adplink samples.ladp $(ADP_OBJ) > src/samples.h
		cat samples.ladp | ./scspadpcm/bintoinc > src/samples.ladp.inc
		rm *.adp

$(OBJ_C) : %.o : %.c
	$(CC) $(CFLAGS) -o $@ -c  $<
	
$(OBJ_S) : %.o : %.s
	$(CC) $(CFLAGS) -o $@ -c $<
	
convert_pal: 
	bin2c $(SRC_PAL) $(C_PAL)  $(basename $(OBJ_PAL))
	$(CC) $(CFLAGS) -o $(OBJ_PAL) -c  $(C_PAL)

clean:
	rm -f $(PRGNAME) *.o *.bin *.elf
