#include p18f4520.inc

ORG 00;
MOVLW 80H;
MOVWF 30H;
MOVFF 30H, 31H;
MOVFF 30H, 32H;
MOVFF 30H, 33H;
MOVFF 30H, 34H;
MOVFF 30H, 35H;
MOVFF 30H, 36H;
MOVFF 30H, 37H;
MOVFF 30H, 38H;
END