#include p18f4520.inc
    org 00
    MOVLW 81H
    MOVWF 20H
    MOVFF 20H, 21H
    MOVFF 20H, 22H
    MOVFF 20H, 23H
    MOVFF 20H, 24H
    COMF 24H
    END
