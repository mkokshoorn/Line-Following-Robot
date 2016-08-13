avr-objcopy -O ihex -R .eeprom output.elf output.hex
avrdude -p m8 -P lpt1 -c spl2
load-pp output