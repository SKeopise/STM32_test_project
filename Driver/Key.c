
#include <Key.h>







void Key_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitKEY;
	GPIO_InitKEY.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitKEY.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitKEY.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOE,&GPIO_InitKEY);
}

unsigned char Key_Driver()
{
	unsigned char KeyNumber = 0;
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == 0);

		KeyNumber = 1;		
	}
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) == 0)
	{
	    Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) == 0);

		KeyNumber = 2;
	}
		
	
    return KeyNumber;
}










