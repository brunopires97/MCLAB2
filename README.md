# MCLAB2
# Autor: Bruno Pires Lourenço

1. INTRODUÇÃO

   Os microprocessadores fazem parte do cotidiano das pessoas em tarefas consideradas básicas, como acordar, dirigir, entre outras. Também, são utilizados em grande escala, como em operações nas indústrias. Por isso, é necessário entender um sistema micro processado para, então, aprender a programa-lo para executar uma
determinada tarefa. O presente trabalho se utilizou do PIC16F877A para o desenvolvimento do projeto que exibe a quantidade de vezes no qual o botão S1 da placa MClab2 foi pressionado. Quando esse contador chega ao valor 9, ele zera a contagem.

2. O PROJETO

   Como supracitado, deve ser exibida a quantidade de vezes no qual o botão S1 foi pressionado. Para isso, foi, primeiramente, desenvolvido o código em linguagem C. Foram deixadas algumas opções de configuração desabilitadas, como pode ser visualizado no código. Assim, selecionou-se a opção em configuration bits (bits de configuração) e marcou-se a opção OFF para todas as opções, exceto a opção Oscillator Selection bits, na qual marcou-se a opção HS. 
   
```
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
```
   
   Após, foi definida a frequência como 8MHz. Para a execução do programa, deixou-se o comando while sempre verdadeiro fazendo, assim, que o programa nunca pare de ser executado (enquanto ele não for fechado). Depois, foi inserido o comando If que informa que se o botão S1 for pressionado, o trecho de código após ele é executado. Com isso, foi utilizado o comando switch-case, que se baseia na variável auxiliar “var”. Quando essa variável é uma das opções entre 1 e 9, o display de sete segmentos acende, referenciando o número de vezes no qual o botão S1 foi pressionado. 
```
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
```
   
   Para a visualização correta de quais led’s acenderiam, foi utilizado o diagrama que se encontra em anexo a este trabalho, cujo recorte pode ser visto na figura 1.
   
   ![Recorte do diagrama da placa](https://github.com/brunopires97/MCLAB2/blob/main/Images/Recorte%20do%20diagrama%20da%20placa.jpg?raw=true)
   
   A cada execução do comando case, a variável era incrementada em 1, fazendo com que o na próxima vez que fosse pressionado, fosse representado o número correto. Foi inserido, também, um delay de 250ms após cada pressionamento para que fosse possível de se visualizar corretamente os dígitos. A figura 2 representa o momento após o terceiro pressionamento de S1, no qual o dígito 3 aparece no display.
   
   ![Representação do dígito quando o botão S1 foi pressionado 3 vezes](https://github.com/brunopires97/MCLAB2/blob/main/Images/Representa%C3%A7%C3%A3o%20do%20d%C3%ADgito%20quando%20o%20bot%C3%A3o%20S1%20foi%20pressionado%203%20vezes.jpg?raw=true)
