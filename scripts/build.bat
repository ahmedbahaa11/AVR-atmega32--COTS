@echo off
make clean
make sync
make all

(
    echo                     Building Process [SUCCESS]
    echo                     ----------------------------
    echo             Developed By Eng. Ahmed Bahaa Nasr
    echo          Automotive Embedded SW Engineer [ADAS]
) > temp.txt

msg * < temp.txt
del temp.txt

@REM pause