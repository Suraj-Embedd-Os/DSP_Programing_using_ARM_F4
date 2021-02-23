
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "arm_math.h"

#define		input_sig_len	320
#define		imp_sig_len		29

/*************function prototype***************/

void plot_singnal(float *sig_src_arr,int sig_lenght);
////////////////////////////////

extern void SystemClock_Config(void);
extern float inputSignal_f32_1kHz_15kHz[input_sig_len];
extern float32_t impulse_response [imp_sig_len] ;


float32_t output_sigal[imp_sig_len+input_sig_len];
float input_mean;
float input_variance;
float input_std;
int main()
{
	 HAL_Init();
	 SystemClock_Config();
	
	arm_conv_f32(&inputSignal_f32_1kHz_15kHz[0],input_sig_len,
							&impulse_response[0],imp_sig_len,&output_sigal[0]);
							
		while(1)
		{
			
		}
}


void plot_singnal(float *sig_src_arr,int sig_lenght)
{
	for(int i=0;i<sig_lenght;++i)
		{
			sig_lenght =sig_src_arr[i];
			for(int j=0;j<3000;j++);
		}
}
void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}