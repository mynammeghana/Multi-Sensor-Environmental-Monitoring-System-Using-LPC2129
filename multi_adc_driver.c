#include"multi_header.h"

void multi_adc_init(void)
{
PINSEL1 |= 0x15400000;
ADCR=0x200400;
}

#define done ((ADDR>>31)&1)
unsigned int multi_adc_read(unsigned int ch_num)
{
unsigned int result=0;
ADCR |= (1<<ch_num);		  //select which channel
ADCR |= (1<<24);   //start adc
while(done==0); //wait for adc converter;
ADCR ^= (1<<24); //stop adc
ADCR ^= (1<<ch_num); //disselct channel
result = (ADDR>>6)&0X3FF; //DATA TO EXTRACT
return result;
}

float adc_temp_sensor(unsigned int ch_num)
{
unsigned int adc_temp_value;
float temp,t_out;
adc_temp_value=multi_adc_read(ch_num);
temp=(adc_temp_value*3.3)/1023;
t_out=temp/0.010;
return t_out;
}

float adc_ldr_sensor(unsigned int ch_num)
{
unsigned int adc_ldr_value=0;
float l_out;
adc_ldr_value=multi_adc_read(ch_num);
l_out=((float)adc_ldr_value/1023.0)*100.0;
l_out=100.0-l_out;
return l_out;
}

float adc_water_sensor(unsigned int ch_num)
{
unsigned int adc_water_value=0;
float w_out;
adc_water_value=multi_adc_read(ch_num);
w_out=((float)adc_water_value/1023.0)*100.0;
return w_out;
}

float adc_soil_sensor(unsigned int ch_num)
{
unsigned int adc_soil_value=0;
float s_out;
adc_soil_value=multi_adc_read(ch_num);
s_out=((float)adc_soil_value/1023.0)*100.0;
s_out=100.0-s_out;
if(s_out>100.0)
s_out=100.0;
else if(s_out<100.0)
s_out=0.0;
return s_out;
}

