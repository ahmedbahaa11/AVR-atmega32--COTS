@echo off
make clean
make sync
make all

@REM (
@REM     echo                     Building Process [SUCCESS]
@REM     echo                     ----------------------------
@REM     echo             Developed By Eng. Ahmed Bahaa Nasr
@REM     echo          Automotive Embedded SW Engineer [ADAS]
@REM ) > temp.txt

@REM msg * < temp.txt
@REM del temp.txt

@REM pause
