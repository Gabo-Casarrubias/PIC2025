/*
 * File:   main.c
 * Author: gabri
 *
 * Created on 4 de julio de 2025, 04:55 PM
 */


// PIC16F18877 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FEXTOSC = OFF    // External Oscillator mode selection bits (EC above 8MHz; PFM set to high power)
#pragma config RSTOSC = HFINT32 // Power-up default value for COSC bits (HFINTOSC with OSCFRQ= 32 MHz and CDIV = 1:1)
#pragma config CLKOUTEN = OFF   // Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (FSCM timer enabled)

// CONFIG2
#pragma config MCLRE = ON       // Master Clear Enable bit (MCLR pin is Master Clear function)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config LPBOREN = OFF    // Low-Power BOR enable bit (ULPBOR disabled)
#pragma config BOREN = ON       // Brown-out reset enable bits (Brown-out Reset Enabled, SBOREN bit is ignored)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices)
#pragma config ZCD = OFF        // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit can be cleared and set only once in software)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)

// CONFIG3
#pragma config WDTCPS = WDTCPS_31// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled, SWDTEN is ignored)
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)

// CONFIG4
#pragma config WRT = OFF        // UserNVM self-write protection bits (Write protection off)
#pragma config SCANE = available// Scanner Enable bit (Scanner module is available for use)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.)

// CONFIG5
#pragma config CP = OFF         // UserNVM Program memory code protection bit (Program Memory code protection disabled)
#pragma config CPD = OFF        // DataNVM code protection bit (Data EEPROM code protection disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>



#include <xc.h>
#define _XTAL_FREQ 32000000

void main(void) {
    TRISA=0;
 unsigned char myByte = 0b11111111;  
	// Operación igual = 
	LATA = myByte;
	
	myByte = 0b10101010;
	LATA = myByte;
	
	myByte = 0b01010101;
	LATA = myByte;
	
	myByte = 0b10000001;
	LATA = myByte;
	
	myByte = 0b00000000;
	LATA = myByte;
	
	// Operación OR  |
	//es como poner en alto un bit sin posibilidad de removerlo
	
	myByte = 0b10000001;
	LATA = LATA | myByte;
	LATA = LATA | myByte;
	
	myByte = 0b00000000;
	LATA = LATA | myByte;
	
	myByte = 0b01000010;
	LATA |= myByte;
	
	myByte = 0b00111100;
	LATA |= myByte;
	
	// Operación AND &
	//Es como poner en bajo un bit sin posibilidad de agregarlo otra vez
	
	myByte = 0b01111110;
	LATA = myByte & LATA;
	LATA = LATA & myByte;
	
	myByte = 0b00111100;
	LATA &= myByte;
	
	myByte = 0b11000011;
	LATA &= myByte;
	
	// Operador complemento ~

	LATA = ~ LATA;
	
	myByte = 0b11000011;
	LATA &= myByte;
	
	LATA = ~ LATA;
	LATA = ~ LATA;
	
	// Corrimineto de bits
	// Moviendo bits 
	
	myByte = 0b00000001;
	LATA = myByte;
	
	// Corrimiento a la izqiuerda
	LATA = myByte << 1;
    LATA = (myByte << 1);
	LATA = LATA << 1;
	LATA = LATA << 1;
	
	LATA = LATA >> 1;
	LATA = LATA >> 2;
	LATA = LATA >> 4;
    
	// Enmascaramiento de bits
	// Modificando un bit en especifico
	
	unsigned char MiSuperImportanteBit = 5;
	// No olvidar que la cuenta empieza en 0
	
	// Para poner en alto el pin
	//1 << 5 --> 0010000
	LATA |= (1<< MiSuperImportanteBit);
	
	// Para poner en bajo el pin 
	//1 << 5 --> 1101111
	
	LATA &= ~(1<< MiSuperImportanteBit);
    
    //Operación XOR
    LATA^=(1<<6);
	LATA^=(1<<6);
    LATA^=(1<<6);
    LATA^=(1<<6);
	while(1)
	{
		
        for(int i = 0; i < 8 ; i++)
		{
			if( i == 0)
			{ 
				myByte = 0 ;
				LATA = myByte;
				__delay_ms(300);
			}
			
			for(int j=0;j<(8-i);j++)
			{	
				__delay_ms(300);
				LATA = myByte | (1 << (7 - j)) ;
			}
			myByte |= 1 << i;
			LATA = myByte;
			__delay_ms(300);
		}
        
		LATA = 0b01010101;
		for(int i=0;i<10;i++)
		{
			__delay_ms(200);
			LATA = ~LATA;
		}
	}
    return;
}
