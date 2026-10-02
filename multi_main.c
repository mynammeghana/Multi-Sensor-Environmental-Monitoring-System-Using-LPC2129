
#include"multi_header.h"
int main()
{
	float t_out,s_out,w_out,ldr_out;
	multi_adc_init();
	multi_lcd_init();
	multi_uart0_init(9600);
	IODIR0=7<<17;

	while(1)
	{
		IOSET0=7<<17;
		t_out=adc_temp_sensor(1);
		w_out=adc_water_sensor(0);
		s_out=adc_soil_sensor(3);
		ldr_out=adc_ldr_sensor(2);

		multi_uart0_tx_string("Temparature:");
		multi_uart0_float(t_out);
		multi_uart0_tx_string("\r\n");
		multi_lcd_cmd(0x80);
		multi_lcd_string("Temp:");
		multi_lcd_float(t_out);
		multi_lcd_data('C');

		if(ldr_out<50)    // change this after checking
			multi_uart0_tx_string("Light Level : NORMAL \r\n");
		else
			multi_uart0_tx_string("Light Level : DARK \r\n");

		multi_uart0_tx_string("Soil moisture :");
		multi_uart0_float(s_out);
		multi_uart0_tx_string("\r\n");


		if(w_out<40)
			multi_uart0_tx_string("Water Sensor : Water Detected \r\n");
		else
			multi_uart0_tx_string("Water Sensor : Water NOT Detected \r\n");

		if(s_out>20){
			if(w_out<40){
				if(t_out<=40 && ldr_out<50)
				{
					multi_lcd_cmd(0xc0);
					multi_lcd_string("system : SAFE" );
					multi_uart0_tx_string("system status : SAFE \r\n");
					IOCLR0=1<<17;
				}

				else if(t_out<=40 && ldr_out>50){
					multi_lcd_cmd(0xc0);
					multi_lcd_string("system : DARK" );
					multi_uart0_tx_string("system status : DARK \r\n");
					IOCLR0=1<<19;
				}

				else if(t_out>40 && ldr_out>50){
					multi_lcd_cmd(0xc0);
					multi_lcd_string("system : HOT/DARK" );
					multi_uart0_tx_string("system status : HOT/DARK \r\n");
					IOCLR0=1<<19;
				}
				else if(t_out>40){
					multi_lcd_cmd(0xc0);
					multi_lcd_string("system : HOT ");
					multi_uart0_tx_string("system status : HOT \r\n");
					IOCLR0=1<<19;
				}
			}
			else
			{
				multi_lcd_cmd(0xc0);
				multi_lcd_string("system : Alert" );
				multi_uart0_tx_string("system status : Alert \r\n");
				IOCLR0=1<<18;
			}
		}
		else
		{
			multi_lcd_cmd(0xc0);
			multi_lcd_string("system:DRY/water needed" );
			multi_uart0_tx_string("system status : DRY/water needed \r\n");
			IOCLR0=1<<18;
		}
	}


}

	
