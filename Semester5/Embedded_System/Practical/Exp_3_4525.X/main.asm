#include p18f4520.inc

org 00;
MOVLW 30H;
MOVWF 90H;
MOVFF 90H, 91H;
MOVFF 91H, 92H;
MOVFF 92H, 93H;
MOVFF 93H, 94H;
MOVFF 94H, 95H;
MOVFF 95H, 96H;
MOVFF 96H, 97H;
MOVFF 97H, 98H;
END;