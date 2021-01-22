/*
 * File:   main.c
 * Author: Bruno Pires Lourenço
 *
 * Created on 9 de Janeiro de 2021, 17:17
 */


// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 8000000U

int var=1; //Variável auxiliar que permite a contagem de pressionamentos. Inicia em 1.

void main(void) {   
    TRISB=0b00001111; //Os 4 bits superiores são saídas digitais.
    PORTB=0;
    TRISD=0;
    PORTD=0;
    
    
    while(1){
        if (PORTB==0b00001110){
            switch(var){
                case 1:
                    RB7=1;
                    RD1=RD2=1;
                    RD0=RD3=RD4=RD5=RD6=0;
                    __delay_ms(250);
                    RB7=0;
                    break;
                case 2:
                    RB7=1;
                    RD0=RD1=RD3=RD4=RD5=RD6=1;
                    RD5=RD2=0;
                    __delay_ms(250);
                    RB7=0;
                    break;
                case 3:
                    RB7=1;
                    RD0=RD1=RD3=RD2=RD5=RD6=1;
                    RD5=RD4=0;
                    __delay_ms(250);
                    RB7=0;
                    break;
                case 4:
                    RB7=1;
                    RD1=RD2=RD5=RD6=1;
                    RD0=RD3=RD4=0;
                    __delay_ms(250);
                    RB7=0;
                    break;
                case 5:
                    RB7=1;
                    RD1=RD4=0;
                    RD0=RD3=RD2=RD5=RD6=1;
                    __delay_ms(250);
                    RB7=0;
                    break;
                case 6:
                    RB7=1;
                    RD1=0;
                    RD0=RD3=RD2=RD4=RD5=RD6=1;
                    __delay_ms(250);
                    RB7=0;
                    break;
                case 7:
                    RB7=1;
                    RD0=RD1=RD2=1;
                    RD3=RD4=RD5=RD6=0;
                    __delay_ms(250);
                    RB7=0;
                    break;
                case 8:
                    RB7=1;
                    RD0=RD1=RD2=RD3=RD4=RD5=RD6=1;
                    __delay_ms(250);
                    RB7=0;
                    break;
                case 9:
                    RB7=1;
                    RD0=RD1=RD2=RD5=RD6=1;
                    RD3=RD4=0;
                    __delay_ms(250);
                    RB7=0;
                    var=0;
                    break;
                default:
                    RB4=RB5=RB6=RB7=0;
            }  
            var++;
        }
    }
    return;
}