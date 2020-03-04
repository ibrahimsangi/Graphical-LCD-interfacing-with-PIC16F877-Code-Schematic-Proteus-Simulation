/* 
 * File:   GraphicalLCD.c
 * Author: IBRAHIM LABS
 * EMAIL:  Ibrahimlabs@gmail.com
 *
 * Website: http://www.ibrahimlabs.com/
 *
 * Created on August 15, 2014, 9:43 PM
 */

#include <xc.h>
#include "GraphicalLCD.h"

#define _XTAL_FREQ  10000000UL   //  10MHz.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitializeGraphicalLCD(void)
{
    ConfigureLCDPINsDirection(Output);
    RegisterSelect = Command;
    EnableLCD = Enable;
    DataBusLCD = Disable;
    ChipSelect1 = Disable;
    ChipSelect2 = Disable;
    ResetLCD = Enable;
    __delay_us(10);

    ResetLCD = Disable;                                 // Normal Operation
    WriteCommandToLCD(DisplayON, BothChip);             //  Sending 63 to both chip CS1 and CS2
    WriteCommandToLCD(DisplayStartLine, BothChip);      //  Sending 192 to both chip CS1 and CS2
    ClearScreen();
}//  © www.IbrahimLabs.com
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChipSelection(unsigned char Chip)
{
    if (Chip == 1)
    {
        ChipSelect1 = Enable;
        ChipSelect2 = Disable;
    }
    else if (Chip == 2)
    {
        ChipSelect1 = Disable;
        ChipSelect2 = Enable;
    }
    else
    {
        ChipSelect1 = Enable;
        ChipSelect2 = Enable;
    }
}//  © www.IbrahimLabs.com
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ToggleEnablePin(void)
{
    __delay_us(1);
    EnableLCD = Enable;
    __delay_us(1);
    EnableLCD = Disable;
}//  © www.IbrahimLabs.com
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WriteCommandToLCD(unsigned char CommandToLCD, unsigned char SelectChip)
{

    // sending data to LCD.
    ChipSelection(SelectChip);
    RegisterSelect = Command;
    DataBusLCD = CommandToLCD;
    ToggleEnablePin();
}//  © www.IbrahimLabs.com
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WriteDataToLCD(unsigned char DataToLCD, unsigned char SelectChip)
{

    // sending data to LCD.
    ChipSelection(SelectChip);
    RegisterSelect = Data;
    DataBusLCD = DataToLCD;
    ToggleEnablePin();
}//  © www.IbrahimLabs.com
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WriteAddressToLCD(unsigned char AddressX, unsigned char AddressY, unsigned char SelectChip)
{
    // sending X address.
    WriteCommandToLCD(AddressX, SelectChip);

    // sending Y address.
    WriteCommandToLCD(AddressY, SelectChip);
}//  © www.IbrahimLabs.com
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ClearScreen(void)
{
    unsigned char X = 0, Y = 0, Page = 0;

    Page = Page0;
    for (X = 0; X < 8; X++)
    {
        WriteAddressToLCD(Page++, Index0, BothChip);
        for (Y = 0; Y < 64; Y++)
            WriteDataToLCD(0x00, BothChip);
    }

}//  © www.IbrahimLabs.com
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void FillScreen(void)
{
    unsigned char X = 0, Y = 0, Page = 0;

    Page = Page0;
    for (X = 0; X < 8; X++)
    {
        WriteAddressToLCD(Page++, Index0, BothChip);
        for (Y = 0; Y < 64; Y++)
            WriteDataToLCD(0xFF, BothChip);

    }
}//  © www.IbrahimLabs.com 

void DisplayPicture(const unsigned char *PtrArray)
{
    unsigned char X = 0, Y = 0, Page = 0;

    Page = Page0;
    for (X = 0; X < 8; X++)
    {
        WriteAddressToLCD(Page, Index0, LeftChip);
        for (Y = 0; Y < 64; Y++)
            WriteDataToLCD(*PtrArray++, LeftChip);

        WriteAddressToLCD(Page++, Index0, RightChip);
        for (Y = 0; Y < 64; Y++)
            WriteDataToLCD(*PtrArray++, RightChip);
    }
}//  © www.IbrahimLabs.com
