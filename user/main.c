#include"pwm.h"
#include"delay.h"
int main(void)	
{
    u16 led0pwmval;	
	delay_init(72);
 	TIM2_PWM_Init(2000,719);	//100Khz�ļ���Ƶ�ʣ�������2000Ϊ20ms   

	  	for(led0pwmval=50;led0pwmval<150;led0pwmval++) 									 
		   {	    
		    TIM_SetCompare3(TIM2,led0pwmval);
	    	delay_ms(15);					 //��ʱ��ú���Ҫ���Լ�һ����ԡ�
		   }
  while(1);

}	
 /*
   while(1)
	{

		for(led0pwmval=100;led0pwmval<200;led0pwmval++) 									 
		   {	    
		    TIM_SetCompare3(TIM2,led0pwmval);
	    	delay_ms(10);					 //��ʱ��ú���Ҫ���Լ�һ����ԡ�
		   }
	   	for(led0pwmval=200;led0pwmval>=101;led0pwmval--) 									 
		   {
		    TIM_SetCompare3(TIM2,led0pwmval);
			delay_ms(10);
		   }
		 
	}
	*/	   

