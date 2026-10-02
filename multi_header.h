#include<lpc21xx.h>

extern void multi_lcd_float(float n);
extern void multi_lcd_int(int num);
extern void multi_lcd_init(void);
extern void multi_lcd_cmd(unsigned char cmd);
extern void multi_lcd_data(unsigned char data);
extern void multi_lcd_string(char *p);

extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);

extern void multi_uart0_float(float n);
extern void multi_uart0_int(int num);
extern void multi_uart0_tx_string(char *ptr);
extern unsigned char multi_uart0_rx(void);
extern void multi_uart0_tx(unsigned char data);
extern void multi_uart0_init(unsigned int baud);

extern void multi_adc_init(void);
extern unsigned int multi_adc_read(unsigned int ch_num);
extern float adc_temp_sensor(unsigned int ch_num);
extern float adc_ldr_sensor(unsigned int ch_num);
extern float adc_water_sensor(unsigned int ch_num);
extern float adc_soil_sensor(unsigned int ch_num);

