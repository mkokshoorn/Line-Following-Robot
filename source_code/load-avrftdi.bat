@ECHO OFF
avrdude -p m8 -c avrftdi -U flash:w:%1.hex:i
