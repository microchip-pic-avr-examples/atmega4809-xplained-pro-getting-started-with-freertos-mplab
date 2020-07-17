
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

ifdef SystemRoot
	SHELL = cmd.exe
	MK_DIR = mkdir
else
	ifeq ($(shell uname), Linux)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), CYGWIN)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW32)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW64)
		MK_DIR = mkdir -p
	endif
endif

# List the subdirectories for creating object files
SUB_DIRS +=  \
 \
src \
freeRTOS/portable/GCC/ATmega4809 \
freeRTOS/portable/MemMang \
freeRTOS \
OLED

# List the object files
OBJS +=  \
freeRTOS/event_groups.o \
src/bod.o \
src/protected_io.o \
freeRTOS/portable/MemMang/heap.o \
clock.o \
OLED/font.o \
LED.o \
keyboard.o \
OLED/ssd1306.o \
freeRTOS/portable/GCC/ATmega4809/port.o \
src/clkctrl.o \
freeRTOS/tasks.o \
driver_isr.o \
freeRTOS/list.o \
src/driver_init.o \
spi0.o \
freeRTOS/timers.o \
src/cpuint.o \
freeRTOS/croutine.o \
main.o \
freeRTOS/queue.o \
freeRTOS/stream_buffer.o \
OLED/oled.o \
atmel_start.o \
terminal.o \
src/slpctrl.o

OBJS_AS_ARGS +=  \
"freeRTOS/event_groups.o" \
"src/bod.o" \
"src/protected_io.o" \
"freeRTOS/portable/MemMang/heap.o" \
"clock.o" \
"OLED/font.o" \
"LED.o" \
"keyboard.o" \
"OLED/ssd1306.o" \
"freeRTOS/portable/GCC/ATmega4809/port.o" \
"src/clkctrl.o" \
"freeRTOS/tasks.o" \
"driver_isr.o" \
"freeRTOS/list.o" \
"src/driver_init.o" \
"spi0.o" \
"freeRTOS/timers.o" \
"src/cpuint.o" \
"freeRTOS/croutine.o" \
"main.o" \
"freeRTOS/queue.o" \
"freeRTOS/stream_buffer.o" \
"OLED/oled.o" \
"atmel_start.o" \
"terminal.o" \
"src/slpctrl.o"

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS +=  \
"freeRTOS/event_groups.d" \
"driver_isr.d" \
"freeRTOS/portable/MemMang/heap.d" \
"freeRTOS/tasks.d" \
"src/bod.d" \
"LED.d" \
"keyboard.d" \
"clock.d" \
"OLED/font.d" \
"src/clkctrl.d" \
"OLED/ssd1306.d" \
"freeRTOS/list.d" \
"src/protected_io.d" \
"spi0.d" \
"src/driver_init.d" \
"main.d" \
"freeRTOS/stream_buffer.d" \
"OLED/oled.d" \
"freeRTOS/croutine.d" \
"src/cpuint.d" \
"freeRTOS/queue.d" \
"atmel_start.d" \
"src/slpctrl.d" \
"freeRTOS/timers.d" \
"terminal.d" \
"freeRTOS/portable/GCC/ATmega4809/port.d"

MAKEFILE_DIR := $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
OUTPUT_FILE_NAME :=AtmelStart
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf

vpath %.c ../
vpath %.s ../
vpath %.S ../

# All Target
all: $(SUB_DIRS) $(OUTPUT_FILE_PATH)

# Linker target




$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker
	$(QUOTE)avr-gcc$(QUOTE) -o $(OUTPUT_FILE_NAME).elf $(OBJS_AS_ARGS)  -Wl,--start-group -lm -Wl,--end-group \
-Wl,-Map="$(OUTPUT_FILE_NAME).map" -Wl,--gc-sections \
-mmcu=atmega4809 -B "$(MAKEFILE_DIR)../gcc/dev/atmega4809" \
-L"../gcc/dev/atmega4809/avrxmega3"  \
-l:libatmega4809.a 
	@echo Finished building target: $@

	"avr-objcopy" -O binary "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).bin"
	"avr-objcopy" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures \
        "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).hex"
	"avr-objcopy" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma \
        .eeprom=0 --no-change-warnings -O binary "$(OUTPUT_FILE_NAME).elf" \
        "$(OUTPUT_FILE_NAME).eep" || exit 0
	"avr-objdump" -h -S "$(OUTPUT_FILE_NAME).elf" > "$(OUTPUT_FILE_NAME).lss"
	"avr-size" "$(OUTPUT_FILE_NAME).elf"

# Compiler target(s)




%.o: %.c
	@echo Building file: $<
	@echo AVR/GNU C Compiler
	$(QUOTE)avr-gcc$(QUOTE) -x c -DF_CPU=3333333 -DDEBUG -Os -ffunction-sections -g3 -Wall -c -std=gnu99 \
-mmcu=atmega4809 -B "$(MAKEFILE_DIR)../gcc/dev/atmega4809" \
    -D__mega4809__ \
-I"../config" -I"../include" -I"../utils" -I"../utils/assembler" -I"../freeRTOS/portable/MemMang" -I"../OLED" -I"../freeRTOS/portable/GCC/ATmega4809" -I"../freeRTOS/include" -I"../" -I"../include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"

	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo AVR/GNU Assembler
	$(QUOTE)avr-gcc$(QUOTE) -x assembler-with-cpp -DF_CPU=3333333 -DDEBUG -Os -ffunction-sections -g3 -Wall -c -std=gnu99 \
-mmcu=atmega4809 -B "$(MAKEFILE_DIR)../gcc/dev/atmega4809" \
    -D__mega4809__ \
-I"../config" -I"../include" -I"../utils" -I"../utils/assembler" -I"../freeRTOS/portable/MemMang" -I"../OLED" -I"../freeRTOS/portable/GCC/ATmega4809" -I"../freeRTOS/include" -I"../" -I"../include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"

	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo AVR/GNU Preprocessing Assembler
	$(QUOTE)avr-gcc$(QUOTE) -x assembler-with-cpp -DF_CPU=3333333 -DDEBUG -Os -ffunction-sections -g3 -Wall -c -std=gnu99 \
-mmcu=atmega4809 -B "$(MAKEFILE_DIR)../gcc/dev/atmega4809" \
    -D__mega4809__ \
-I"../config" -I"../include" -I"../utils" -I"../utils/assembler" -I"../freeRTOS/portable/MemMang" -I"../OLED" -I"../freeRTOS/portable/GCC/ATmega4809" -I"../freeRTOS/include" -I"../" -I"../include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"

	@echo Finished building: $<

# Detect changes in the dependent files and recompile the respective object files.
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(DEPS)),)
-include $(DEPS)
endif
endif

$(SUB_DIRS):
	$(MK_DIR) "$@"

clean:
	rm -f $(OBJS_AS_ARGS)
	rm -f $(OUTPUT_FILE_PATH)
	rm -f $(DEPS_AS_ARGS)
	rm -f $(OUTPUT_FILE_NAME).a $(OUTPUT_FILE_NAME).hex $(OUTPUT_FILE_NAME).bin \
        $(OUTPUT_FILE_NAME).lss $(OUTPUT_FILE_NAME).eep $(OUTPUT_FILE_NAME).map \
        $(OUTPUT_FILE_NAME).srec
