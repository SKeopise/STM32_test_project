#include "stm32f10x.h"                  // Device header
#include <Delay.h>
#include <led.h>
#include <Key.h>
#include <init.h>
#include <Timer.h>
#include <OLED.h>

uint8_t keynumber = 0;

int main()
{
	int cnt=0;
	
	Led_Init();
	BEEP_Init();
	Key_Init();
	CountSensor_Init();
	Timer_Init();
	OLED_Init();
	
//	OLED_ShowChar(1, 1, 'A');
//	OLED_ShowString(2, 1, "asbdjdaw");
//	OLED_ShowNum(3, 1, 3424, 4);
//	OLED_ShowBinNum(4, 1, 0x3f, 8);
	
	while(1)
	{
		keynumber = Key_Driver();
		if(keynumber == 1)
		{
			LED1_ON();
			LED2_OFF();
			cnt++;
			OLED_ShowNum(3, 1, cnt, 4);
			BEEP_ON();
			Delay_ms(200);
			BEEP_OFF();			
		}
		else if(keynumber == 2)
		{
			LED2_ON();
			LED1_OFF();
			cnt--;
			OLED_ShowNum(3, 1, cnt, 4);
			BEEP_ON();
			Delay_ms(200);
			BEEP_OFF();				
		}
//		LED1_ON();
//		Delay_ms(500);
//		LED1_OFF();
//		Delay_ms(500);
//		LED2_ON();
//		Delay_ms(500);
//		LED2_OFF();
//		Delay_ms(500);
//		BEEP_ON();
//		Delay_ms(1000);
//		BEEP_OFF();
//	
	}

}


















