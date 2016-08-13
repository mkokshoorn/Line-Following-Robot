@ECHO OFF

REM Fuses 11100001 (E1) enables BOD
REM avrdude -p m8 -P lpt1 -c sp12 -U flash:w:%1.hex -U lfuse:w:0xE1:m -E noreset

REM Without fuses
avrdude -p m8 -P lpt1 -c sp12 -U flash:w:%1.hex -E noreset