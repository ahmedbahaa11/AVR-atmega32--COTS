@echo off
make clean
make sync
make all

(
    echo                        Building Process [SUCCESS]
    echo                      ------------------------------
    echo                            Eng _ Mostafa Samir
    echo                Embedded System Software Engineer
) > temp.txt

msg * < temp.txt
del temp.txt

@REM pause
