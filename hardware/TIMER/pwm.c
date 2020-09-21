#include"pwm.h"

void TIM2_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//ʹ�ܶ�ʱ��3ʱ��
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA  | RCC_APB2Periph_AFIO, ENABLE);//ʹ��GPIO�����AFIO���ù���ģ��ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE );// ����AFIOҲ����
    //���ø�����Ϊ�����������,���TIM2 CH3��PWM���岨��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //TIM_CH3��ͨ��3����PA2��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //����������������ùؼ�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

   //��ʼ��TIM2
	TIM_TimeBaseStructure.TIM_Period = arr;   //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); 
	
	//��ʼ��TIM2 Channel3 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ�ܣ�ʹ��PWM������˿ڡ�
//	TIM_OCInitStructure.TIM_Pulse=127;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;//�������:TIM����Ƚϼ���
	TIM_OC3Init(TIM2, &TIM_OCInitStructure); 

	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2��CCR2�ϵ�Ԥװ�ؼĴ���
 	TIM_ARRPreloadConfig(TIM2, ENABLE);                //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���

	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIM3�ܿ���
}
