#include"multi_header.h"

void multi_uart0_init(unsigned int baud)
{
unsigned int pclk,result=0;
if(VPBDIV==0)
   pclk=15000000;
else if(VPBDIV==1)
   pclk=60000000;
else if(VPBDIV==2)
   pclk=30000000;

result=pclk/(16*baud);
PINSEL0 |= 0X05;
U0LCR=0X83;
U0DLL=result&0xff;
U0DLM=(result>>8)&0xff;
U0LCR=0x03;
}

void multi_uart0_tx(unsigned char data)
{
U0THR=data;
while(((U0LSR>>5)&1)==0);
}

unsigned char multi_uart0_rx(void)
{
while((U0LSR&1)==0);
return U0RBR;
}

void multi_uart0_tx_string(char *ptr)
{
while(*ptr)
{
multi_uart0_tx(*ptr);
ptr++;
}
}

void multi_uart0_int(int num)
{
int a[10],i=0;
if(num==0)
multi_uart0_tx('0');

if(num<0)
{
num=-num;
multi_uart0_tx('-');
}
while(num>0)
{
a[i]=num%10+48;
num=num/10;
i++;
}

for(i=i-1;i>=0;i--)
multi_uart0_tx(a[i]);
return ;
}

void multi_uart0_float(float n)
{
int num;
if(n==0)
{
multi_uart0_tx('0');
return ;
}
else if(n<0)
{
n=-n;
multi_uart0_tx('-');
}
//else if(n>0)
//{
num=n;
multi_uart0_int(num);
multi_uart0_tx('.');
num=(n-num)*1000000;
multi_uart0_int(num);
return ;
//}
}

