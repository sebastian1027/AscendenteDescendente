/*
 * File:   AscendenteDescendente.c
 * Author: Sebastianl
 *
 * Created on 30 de agosto de 2017, 12:26 AM
 */
#include <xc.h>
#include <stdio.h>
#include "config.h"
const int retraso = 5000;

void main(void) {
    
    TRISB = 0;
    PORTB = 0;
    TRISC = 1;
    PORTC = 0;
    while (1) {
        
    if (PORTCbits.RC1 == 0 && PORTCbits.RC2 ==0){
        PORTB = 0x00;            
    }        

    if (PORTCbits.RC2 == 1){        //Empieza a incrementar el Display 7 Segmentos
        PORTB = 0x3F; //NUMERO 0
        __delay_ms(retraso);        
        PORTB = 0x06; //NUMERO 1        
        __delay_ms(retraso);
        PORTB = 0x5B; //NUMERO 2
        __delay_ms(retraso);
        PORTB = 0x4F; //NUMERO 3
        __delay_ms(retraso);
        PORTB = 0x66; //NUMERO 4
        __delay_ms(retraso);
        PORTB = 0x6D; //NUMERO 5
        __delay_ms(retraso);
        PORTB = 0x7D; //NUMERO 6
        __delay_ms(retraso);
        PORTB = 0x07; //NUMERO 7
        __delay_ms(retraso);
        PORTB = 0x7F; //NUMERO 8
        __delay_ms(retraso);
        PORTB = 0x6F; //NUMERO 9
        __delay_ms(retraso);
        
    }
    
    if (PORTCbits.RC1 == 1){        
        PORTB = 0x6F; //NUMERO 9
        __delay_ms(retraso);
        PORTB = 0x7F; //NUMERO 8
        __delay_ms(retraso);
        PORTB = 0x07; //NUMERO 7
        __delay_ms(retraso);
        PORTB = 0x7D; //NUMERO 6
        __delay_ms(retraso);
        PORTB = 0x6D; //NUMERO 5
        __delay_ms(retraso);
        PORTB = 0x66; //NUMERO 4
        __delay_ms(retraso);
        PORTB = 0x4F; //NUMERO 3
        __delay_ms(retraso);
        PORTB = 0x5B; //NUMERO 2
        __delay_ms(retraso);
        PORTB = 0x06; //NUMERO 1
        __delay_ms(retraso);
        PORTB = 0x3F; //NUMERO 0
        __delay_ms(retraso);        
    }    
   }
}
/*
 * Catodo             Anodo
 * 0= 0x3F              0xC0
 * 1= 0x06              0xF9
 * 2=0x5B               0xA4
 * 3=0x4F               0xB0
 * 4=0x66               0x99
 * 5=0x6D               0x92
 * 6=0x7D               0x82
 * 7=0x07               0xF8
 * 8=0x7F               0x80
 * 9=0x6F               0x90
 * 
 */