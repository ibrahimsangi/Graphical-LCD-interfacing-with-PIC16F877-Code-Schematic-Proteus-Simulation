/* 
 * File:   main.c
 * Author: IBRAHIM LABS
 * EMAIL:  Ibrahimlabs@gmail.com
 *
 * Website: http://www.ibrahimlabs.com/
 *
 * Created on August 15, 2014, 8:45 PM
 */

#include <xc.h>

#include "GraphicalLCD.h"
#include "Picture.h"

#define _XTAL_FREQ 10000000UL   //  10MHz.

// CONFIG
#pragma config FOSC = HS            // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF           // Watchdog Timer Enable bit (WDT Disabled)
#pragma config PWRTE = OFF          // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF             // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON           // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF            // Low Voltage In-Circuit Serial Programming Disable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF            // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF            // FLASH Program Memory Write Disable (Unprotected program memory may be written to by EECON control)

/*
 * 
 */
int main() {

    InitializeGraphicalLCD();

    while(1)
    {
        FillScreen();
        __delay_ms(1000);
        ClearScreen();
        __delay_ms(1000);
        DisplayPicture(Picture1);
        __delay_ms(1000);
    }

    return 0;
}//  © www.IbrahimLabs.com

