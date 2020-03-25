# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS 	= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: mainFiles.elf 

#additional rules for files
mainFiles.elf: ${COMMON_OBJECTS} mainFunction.o stateMachines.o led.o buzzer.o switches.o p1_interrupt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: mainFiles.elf
	msp430loader.sh mainFiles.elf

clean:
	rm -f *.o *.elf 

buzzer.c: buzzer.h
mainFunction.c: buzzer.h switches.h
switches.c: switches.h buzzer.h led.h
p1_interrupt_handler.c: switches.h led.h stateMachines.h
led.c: led.h stateMachines.h
stateMachine.c: stateMachines.h led.h switches.h
