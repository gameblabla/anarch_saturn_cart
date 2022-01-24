PRGNAME     = installer.elf
CC			= /opt/saturn/bin/sh-elf-gcc 

SRCDIR		= ./src ./assets iapetus/src
#SRCDIR		+= iapetus/src/ar iapetus/src/cd iapetus/src/file iapetus/src/modem iapetus/src/peripherals iapetus/src/scu iapetus/src/sh2 iapetus/src/sound iapetus/src/ui iapetus/src/video
VPATH		= $(SRCDIR)
SRC_C		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
SRC_CP		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cpp))
SRC_S		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.s))
OBJ_C		= $(notdir $(patsubst %.c, %.o, $(SRC_C)))
OBJ_CP		= $(notdir $(patsubst %.cpp, %.o, $(SRC_CP)))
OBJ_S		= $(notdir $(patsubst %.s, %.o, $(SRC_S)))


SRC_PCX		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.pcx))
C_PCX		= $(notdir $(patsubst %.pcx, %.c, $(SRC_PCX)))
OBJ_PCX		= $(notdir $(patsubst %.pcx, %.o, $(SRC_PCX)))

OBJS		= $(OBJ_C) $(OBJ_CP) $(OBJ_PCX)

CFLAGS		= -Ofast -m2 -mno-ieee -mbitops -mfmovd -fno-PIC -flto -Isrc/inc
CFLAGS		+= -Isource 
CFLAGS		+= -Iinclude
CFLAGS		+= -DMISSING_SYSCALL_NAMES -DREENTRANT_SYSCALLS_PROVIDED 

LDFLAGS     = -no-pie -Wl,--as-needed -Wl,--gc-sections -s

all: convert_pcx $(OBJ_C) $(OBJ_S) $(PRGNAME)

# Rules to make executable
$(PRGNAME): $(OBJS)
	$(CC) $(CFLAGS) -Wall -nostartfiles -Wl,--script,src/bart.lk $(OBJ_S) $^ lib/libiapetus.a -o $(PRGNAME) 
	/opt/saturn/bin/sh-elf-objcopy --output-format=binary $(PRGNAME) installer.bin

$(OBJ_C) : %.o : %.c
	$(CC) $(CFLAGS) -o $@ -c  $<
	
$(OBJ_S) : %.o : %.s
	$(CC) $(CFLAGS) -o $@ -c $<
	
convert_pcx: 
	bin2c $(SRC_PCX) $(C_PCX)  $(basename $(OBJ_PCX))
	$(CC) $(CFLAGS) -o $(OBJ_PCX) -c  $(C_PCX)

clean:
	rm -f $(PRGNAME) *.o *.bin *.elf
