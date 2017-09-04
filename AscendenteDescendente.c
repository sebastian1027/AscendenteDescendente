/*
 * File:   AscendenteDescendente.c
 * Author: Sebastianl
 *
 * Created on 30 de agosto de 2017, 12:26 AM
 */
#include <xc.h>
#include <stdio.h>
#include "config.h"
#define retraso 500 //define el retraso de 500 milisegundos


int bandera = 0; //declaracion de la variable que nos va a servir para leer el estado del boton
void tabla(int num); //funcion tabla, con variable int, que representa los numeros
void main(void) {
    
    TRISB = 0; //PUERTO B como salidas
    PORTB = 0; //limpia el PUERTO B 
    TRISC = 1; //PUERTO C como entrada
    PORTC = 0; //PUERTO C como salida
    int contador=0; //numero en el que empieza el display
    while (1) {
        if(PORTCbits.RC1 == 1) // pregunta si se presiono el pin 1 del puerto C
            bandera = 1;        //de ser asi bandera le asigna el valor 1
        if(PORTCbits.RC2 == 1)  // pregunta si se presiono el pin 1 del puerto C
            bandera = 2;        //de ser asi bandera le asigna el valor 2
        tabla(contador);        //numeros que van a salir en el contador
        __delay_ms(retraso);    //pone el retraso de 500 milisegundos
        if(bandera==1)          //si bandera tiene el valor de 1
            contador++;         //empiece el conteo ascedente 
        else if(bandera==2)     //si bandera es igual a 2 
            contador--;         //haga el conteo descendente
        if(contador==10&&bandera==1) //si esta ascendiendo y el contador llega a 9
            contador=0;             //el siguiente numero a mostrar sera 0
        if(contador==-1&&bandera==2) //si el contador esta descendiendo y llega  a 0 
            contador=9;                //el siguiente numero a mostra sera 9
        
    }
        
        
}


// funcion que pone los numeros en el display 
void tabla(int num){
        int aux = num; // variable auxiliar para que al presionar 
                        //un boton u otro sepa en cual numero se quedo para asi poder ascender o descender
        switch(aux)  
        {
           case 0:  //cuando el contador empieza en 0
           PORTB = 0x3F; //NUMERO 0    // muestre el numero 0 en el display
           break;   //quiebre
           case 1:  //cuando el contador pasa a 1
           PORTB = 0x06;//NUMERO 1        //mestre el numero 1 en el display
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
/* //numeros dependiendo si el display 7 segmentos es catodo o anodo comun
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