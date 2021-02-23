
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "arm_math.h"

#define		input_sig_len	320
#define		imp_sig_len		29

/*************function prototype***************/

float signal_mean(float *sig_src_arr,int sig_length);
float signal_variance(float *sig_src_arr,float _mean,int sig_length);
float signal_std(float _variance);
void plot_singnal(float *sig_src_arr,int sig_lenght);
void convolutions(float *sig_src_arr,int sig_length,
									float *sig_imp_arr,int sig_imp_length,
									float *dest_arr);
////////////////////////////////

extern void SystemClock_Config(void);
extern float inputSignal_f32_1kHz_15kHz[input_sig_len];
extern float32_t impulse_response [imp_sig_len] ;

float32_t output_sigal[imp_sig_len+input_sig_len];
float input_mean;
float input_variance;
float input_std;
float input_signal;
int main()
{
	 HAL_Init();
	 SystemClock_Config();
	
//	 //input_mean=signal_mean((float *)&inputSignal_f32_1kHz_15kHz[0], (int) input_sig_len);
//		
//	arm_mean_f32((float *)&inputSignal_f32_1kHz_15kHz[0], (int) input_sig_len,&input_mean);
//	//input_variance=signal_variance((float *)&inputSignal_f32_1kHz_15kHz[0],(float) input_mean,(int) input_sig_len);
//	arm_var_f32((float *)&inputSignal_f32_1kHz_15kHz[0],(int) input_sig_len,&input_variance);
//	
//	input_std= signal_std((float) input_variance);
//	arm_std_f32((float *)&inputSignal_f32_1kHz_15kHz[0],(int) input_sig_len,&input_std);
		while(1)
		{
			
		}
}
void convolutions(float *sig_src_arr,int sig_length,
									float *sig_imp_arr,int sig_imp_length,
									float *dest_arr)
	{
			uint16_t i,j,k;
		for(i=0;i<sig_length+sig_imp_length;++i)
		dest_arr[i]=0;
		
		for(i=0;i<sig_length;i++)
		{
			for(j=0;j<sig_imp_length;j++)
			{
				dest_arr[i+j] = dest_arr[i+j]+sig_src_arr[i]*sig_imp_arr[j];
			}
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