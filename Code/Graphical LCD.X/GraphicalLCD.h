/*
 * File:   GraphicalLCD.h
 * Author: IBRAHIM LABS
 * EMAIL:  Ibrahimlabs@gmail.com
 *
 * Website: http://www.ibrahimlabs.com/
 *
 * Created on August 15, 2014, 9:43 PM
 */

#ifndef GRAPHICALLCD_H
#define	GRAPHICALLCD_H

#ifdef	__cplusplus
extern "C" {
#endif


// LCD Port and Connection Configurations

#define Output 0
    
#define ConfigureLCDPINsDirection(Value)    (TRISD = Value,             \
                                             TRISCbits.TRISC3 = Value,  \
                                             TRISCbits.TRISC4 = Value,  \
                                             TRISCbits.TRISC5 = Value,  \
                                             TRISCbits.TRISC6 = Value,  \
                                             TRISCbits.TRISC7 = Value)

#define DataBusLCD      PORTD
#define RegisterSelect  PORTCbits.RC3
#define EnableLCD       PORTCbits.RC4
#define ChipSelect1     PORTCbits.RC5
#define ChipSelect2     PORTCbits.RC6
#define ResetLCD        PORTCbits.RC7

#define Enable  1
#define Disable 0

#define Command 0
#define Data    1

#define DisplayON        63
#define DisplayStartLine 192

#define LeftChip    1
#define RightChip   2
#define BothChip    3

// LCD Index addresses
#define Index0  0x40
#define Index1  0x50
#define Index2  0x60
#define Index3  0x70
#define Index4  0x80
#define Index5  0x90
#define Index6  0xA0
#define Index7  0xB0

// LCD Pages address
#define Page0   0xB8
#define Page1   0xB9
#define Page2   0xBA
#define Page3   0xBB
#define Page4   0xBC
#define Page5   0xBD
#define Page6   0xBE
#define Page7   0xBF

#define ColourON    1
#define ColourOFF   0

    void InitializeGraphicalLCD(void);
    void ChipSelection(unsigned char Chip);
    void ToggleEnablePin(void);
    void WriteCommandToLCD(unsigned char CommandToLCD, unsigned char SelectChip);
    void WriteDataToLCD(unsigned char DataToLCD, unsigned char SelectChip);
    void WriteAddressToLCD(unsigned char AddressX, unsigned char AddressY, unsigned char SelectChip);
    void ClearScreen(void);
    void FillScreen(void);
    void DisplayPicture(const unsigned char *PtrArray);



#ifdef	__cplusplus
}
#endif

#endif	/* GRAPHICALLCD_H */

