PRGNAME     = installer.elf
CC			= /opt/saturn/bin/sh-elf-gcc 

SRCDIR		= ./src
VPATH		= $(SRCDIR)
SRC_C		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
SRC_CP		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cpp))
SRC_S		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.s))
OBJ_C		= $(notdir $(patsubst %.c, %.o, $(SRC_C)))
OBJ_CP		= $(notdir $(patsubst %.cpp, %.o, $(SRC_CP)))
OBJ_S		= $(notdir $(patsubst %.s, %.o, $(SRC_S)))
OBJS		= $(OBJ_C) $(OBJ_CP)

CFLAGS		= -O2 -Wall -DMISSING_SYSCALL_NAMES -DREENTRANT_SYSCALLS_PROVIDED
CFLAGS		+= -Isource 
CFLAGS		+= -Iinclude

LDFLAGS     = 

all: $(OBJ_C) $(OBJ_S) $(PRGNAME)

# Rules to make executable
$(PRGNAME): $(OBJ_C)
	$(CC) -O2 -Wall -nostartfiles -Wl,--script,src/bart.lk $(OBJ_S) $^ lib/libiapetus.a -o $(PRGNAME) 
	/opt/saturn/bin/sh-elf-objcopy --output-format=binary $(PRGNAME) installer.bin

$(OBJ_C) : %.o : %.c
	$(CC) $(CFLAGS) -o $@ -c  $<
	
$(OBJ_S) : %.o : %.s
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(PRGNAME) *.o *.bin *.elf
