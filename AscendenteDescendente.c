/*
 * File:   AscendenteDescendente.c
 * Author: Sebastianl
 *
 * Created on 30 de agosto de 2017, 12:26 AM
 */
#include <xc.h>
#include <stdio.h>
#include "config.h"
#define retraso 1000

int bandera = 0;
int estadoAnteriorIncremento, estadoAnteroriDecremento;
void tabla(int num);
void main(void) {
    
    TRISB = 0;
    PORTB = 0;
    TRISC = 1;
    PORTC = 0;
    int contador=0;
    while (1) {
        if(PORTCbits.RC1 == 1)
            bandera = 1;
        if(PORTCbits.RC2 == 1)
            bandera = 2;
        tabla(contador);
        __delay_ms(retraso);
        if(bandera==1)
            contador++;
        else if(bandera==2)
            contador--;
        if(contador==10&&bandera==1)
            contador=0;
        if(contador==-1&&bandera==2)
            contador=9; 
        
    }
        
        
}



void tabla(int num){
        int aux = num;
        switch(aux)
        {
           case 0:
           PORTB = 0x3F; //NUMERO 0    
           break;
           case 1:
           PORTB = 0x06;//NUMERO 1        
           break;
           case 2:
           PORTB = 0x5B; //NUMERO 2
           break;
           case 3:
        PORTB = 0x4F; //NUMERO 3
            break;
            case 4:
        PORTB = 0x66; //NUMERO 4
        break;
        case 5: 
        PORTB = 0x6D; //NUMERO 5
        break;
            case 6:        
        PORTB = 0x7D; //NUMERO 6
        break;
            case 7:
        PORTB = 0x07; //NUMERO 7
        break;
            case 8:
        PORTB = 0x7F; //NUMERO 8
        break;
            case 9:
        PORTB = 0x6F; //NUMERO 9
        break;
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