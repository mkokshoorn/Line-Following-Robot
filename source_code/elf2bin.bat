avr-objcopy.exe -O binary -R .eeprom -R .fuse -R .lock -R .signature %1.elf %1.bin