#include p18f4520.inc ; Include the library
    org 00 ; Start at 00
    MOVLW 0x44 ; Move 44H to WREG
    ADDLW 0xFF ; ADD FFH to WREG and send it back
    END ; End 