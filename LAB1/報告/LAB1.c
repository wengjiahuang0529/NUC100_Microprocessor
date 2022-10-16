/**************************************************************************//**
 * @file     main.c
 * @version  V2.00
 * $Revision: 2 $
 * $Date: 15/04/13 4:26p $
 * @brief    Show how to set GPIO pin mode and use pin data input/output control.
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include "NUC100Series.h"
#include "GPIO.h"
#include "SYS.h"
#include "Seven_Segment.h"
#include "Scankey.h"
#define PLL_CLOCK           50000000


void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Enable Internal RC 22.1184MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_OSC22M_EN_Msk);

    /* Waiting for Internal RC clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_OSC22M_STB_Msk);

    /* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HIRC, CLK_CLKDIV_HCLK(1));

    /* Enable external XTAL 12MHz clock */
    CLK_EnableXtalRC(CLK_PWRCON_XTL12M_EN_Msk);

    /* Waiting for external XTAL clock ready */
    CLK_WaitClockReady(CLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(PLL_CLOCK);

    /* Enable UART module clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Select UART module clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV_UART(1));

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Set GPB multi-function pins for UART0 RXD and TXD */
    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB0_Msk | SYS_GPB_MFP_PB1_Msk);
    SYS->GPB_MFP |= (SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD);
}


void UART0_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART0 */
    SYS_ResetModule(UART0_RST);

    /* Configure UART0 and set UART0 Baudrate */
    UART_Open(UART0, 115200);
}

/*
void Show_seven_segment()
{
	//1=on,0=off
			PC4=1; //�̥k��
			PC5=0;
			PC6=0;
			PC7=0;
		
			//0=on,1=off
			PE0=0;
			PE1=1;
			PE2=0;
			PE3=0;
			PE4=0;
			PE5=0;
			PE6=0;
			PE7=1;
			CLK_SysTickDelay(50);
			//print(0)-----------------------//
		
			PC4=0;
			PC5=1;
			PC6=0;
			PC7=0;
			
			PE0=0;
			PE1=1;
			PE2=1;
			PE3=0;
			PE4=0;
			PE5=0;
			PE6=1;
			PE7=0;
			CLK_SysTickDelay(50); 
			//print(3)-----------------------//	
			
			PC4=0;
			PC5=0;
			PC6=1;
			PC7=0;
			
			PE0=0;
			PE1=1;
			PE2=0;
			PE3=0;
			PE4=0;
			PE5=0;
			PE6=0;
			PE7=1;
			CLK_SysTickDelay(50);
			//print(0)-------------------------//	
			
			PC4=0;
			PC5=0;
			PC6=0;
			PC7=1;
			
			PE0=0;
			PE1=1;
			PE2=0;
			PE3=0;
			PE4=0;
			PE5=0;
			PE6=0;
			PE7=1;
			CLK_SysTickDelay(50);
			//print(0)--------------------------//
}
*/
void Bonus()
{
				PA0=1;PA1=1;PA2=0;PA3=1;PA5=1;
			if(PA3==0){//return 1
				PC4=1;
				PC5=0;
				PC6=0;
				PC7=0;
				
				PE0=0;
				PE4=0;
				PE1=1;
				PE2=1;
				PE3=1;
				PE4=0;
				PE5=1;
				PE6=1;
				PE7=1;
				CLK_SysTickDelay(50000000);
			}

			if(PA4==0){//return 4
				PC4=1;
				PC5=0;
				PC6=0;
				PC7=0;
				
				PE2=0;
				PE7=0;
				PE4=0;
				PE0=0;
				PE1=1;
				PE3=1;
				PE5=1;
				PE6=1;
				CLK_SysTickDelay(50000000);
			}
			
			if(PA5==0){//return 7
				PC4=1;
				PC5=0;
				PC6=0;
				PC7=0;
				
				PE0=0;
				PE3=0;
				PE4=0;
				PE1=1;
				PE2=1;
				PE5=1;
				PE6=1;
				PE7=1;
				CLK_SysTickDelay(50000000);
			}

			 PA0=1; PA1=0; PA2=1; PA3=1; PA4=1; PA5=1;
				if(PA3==0){//return 2
					PC4=1;
					PC5=0;
					PC6=0;
					PC7=0;
					
					PE0=1;
					PE1=1;
					PE2=1;
					PE3=0;
					PE4=0;
					PE7=0;
					PE6=0;
					PE5=0;
					CLK_SysTickDelay(50000000);
				}
				if(PA4==0){//return 5
					PC4=1;
					PC5=0;
					PC6=0;
					PC7=0;
					
					PE3=0;
					PE2=0;
					PE7=0;
					PE0=0;
					PE5=0;
					PE1=1;
					PE4=1;
					PE6=1;
					CLK_SysTickDelay(50000000);
				}
				if(PA5==0){//return 8
					PC4=1;
					PC5=0;
					PC6=0;
					PC7=0;
					
					PE0=0;
					PE2=0;
					PE3=0;
					PE4=0;
					PE5=0;
					PE6=0;
					PE7=0;
					PE1=1;
					CLK_SysTickDelay(50000000);
				}
//---------------------------------------------------//
				PA0=0; PA1=1; PA2=1; PA3=1; PA4=1; PA5=1;
				if(PA3==0)//return 3
				{		
					PC4=1;
					PC5=0;
					PC6=0;
					PC7=0;
					
					PE1=1;
					PE0=0;
					PE2=1;
					PE3=0;
					PE4=0;
					PE5=0;
					PE6=1;
					PE7=0;
					CLK_SysTickDelay(50000000);
				}
				
				if(PA4==0)//return 6
				{
					PC4=1;
					PC5=0;
					PC6=0;
					PC7=0;
					
					PE1=1;
					PE0=0;
					PE2=0;
					PE3=0;
					PE4=1;
					PE5=0;
					PE6=0;
					PE7=0;
					CLK_SysTickDelay(50000000);
				}
				if(PA5==0)//return 9
				{
					PC4=1;
					PC5=0;
					PC6=0;
					PC7=0;
					
					PE1=1;
					PE0=0;
					PE2=0;
					PE3=0;
					PE4=0;
					PE5=0;
					PE6=1;
					PE7=0;
					CLK_SysTickDelay(50000000);
				}
}


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int main(void)
{
	//OpenSevenSegment();
	while(1){	
		
			ShowSevenSegment(0,0);
			CLK_SysTickDelay(50);
			CloseSevenSegment();
		
			ShowSevenSegment(1,3);
			CLK_SysTickDelay(50);
			CloseSevenSegment();
		
			ShowSevenSegment(2,0);
			CLK_SysTickDelay(50);
			CloseSevenSegment();
		
			ShowSevenSegment(3,0);
			CLK_SysTickDelay(50);
			CloseSevenSegment();
			
			Bonus();
		}
}



