
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "arm_math.h"

#define		input_sig_len	320

/*************function prototype***************/

float signal_mean(float *sig_src_arr,int sig_length);
float signal_variance(float *sig_src_arr,float _mean,int sig_length);
float signal_std(float _variance);
void plot_singnal(float *sig_src_arr,int sig_lenght);
////////////////////////////////

extern void SystemClock_Config(void);
extern float inputSignal_f32_1kHz_15kHz[input_sig_len];



float input_mean;
float input_variance;
float input_std;
int main()
{
	 HAL_Init();
	 SystemClock_Config();
	
	 //input_mean=signal_mean((float *)&inputSignal_f32_1kHz_15kHz[0], (int) input_sig_len);
		
	arm_mean_f32((float *)&inputSignal_f32_1kHz_15kHz[0], (int) input_sig_len,&input_mean);
	//input_variance=signal_variance((float *)&inputSignal_f32_1kHz_15kHz[0],(float) input_mean,(int) input_sig_len);
	arm_var_f32((float *)&inputSignal_f32_1kHz_15kHz[0],(int) input_sig_len,&input_variance);
	
	input_std= signal_std((float) input_variance);
	arm_std_f32((float *)&inputSignal_f32_1kHz_15kHz[0],(int) input_sig_len,&input_std);
		while(1)
		{
			
		}
}

float signal_mean(float *sig_src_arr,int sig_length)
{
	float _mean=0.0f;
	uint16_t i;
	for(i=0;i<sig_length;i++)
	{
			_mean +=sig_src_arr[i];
	}
	return _mean;
}

float signal_variance(float *sig_src_arr,float _mean,int sig_length)
{
	float _variance=0.0f;
	uint16_t i;
	for(i=0;i<sig_length;i++)
	{
			_variance +=	pow((sig_src_arr[i]-_mean),2);
	}
	return _variance/(sig_length-1);
}
float signal_std(float _variance)
{
	float	_std_variance= sqrt(_variance);
	return _std_variance;
}

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}