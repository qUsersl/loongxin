/*
 * BH1750.c
 *
 * created: 2024/5/19
 *  author: 
 */

#include "config.h"
#include "BH1750.h"


extern void gpio_init(unsigned char gpio,unsigned char io);
extern void gpio_write(unsigned char gpio,unsigned char val);
extern unsigned char gpio_read(unsigned char gpio);
extern void delay_us(unsigned int us);
extern void delay_ms(unsigned int ms);


#define SlaveAddress 0x46 //0x46	


unsigned char CY;
unsigned int LX;


//sbit SDA = P3^4;//gpio5
//sbit SCL = P2^4;//gpio4


void gpio_BH1750_init(void)
{
    gpio_init(5,1);
    gpio_init(4,1);
}



void BH1750_Start()
{
    gpio_write(5,1);          
    gpio_write(4,1);                 
    delay_us(5);                
    gpio_write(5,0);                 
    delay_us(5);               
    gpio_write(4,0);                
}


void BH1750_Stop()
{
    gpio_write(5,0);                   
    gpio_write(4,1);                  
    delay_us(5);                    
    gpio_write(5,1);                
    delay_us(5);                
}


void BH1750_SendACK(unsigned char ack)
{
    gpio_write(5,ack);
    gpio_write(4,1);                  
    delay_us(5);                 
    gpio_write(4,0);              
    delay_us(5);                   
}


unsigned char BH1750_RecvACK()
{
    gpio_write(4,1);             
    gpio_init(5,0);
    delay_us(5);               
    //gpio_init(5,0);
    CY = gpio_read(5);           
    gpio_init(5,1);
    gpio_write(4,0);              
    delay_us(5);                 

    return CY;
}


void BH1750_SendByte(BYTE dat)
{
    unsigned int i;

    for (i=0; i<8; i++)         
    {
        if((dat&0x80)==0x80)
            CY=1;
        else CY=0;
        gpio_write(5,CY);                
        dat <<= 1;             
        gpio_write(4,1);             
        delay_us(5);              
        gpio_write(4,0);                 
        delay_us(5);           
    }
    BH1750_RecvACK();
}



BYTE BH1750_RecvByte()
{
    unsigned int i;
    unsigned int dat = 0;

    gpio_write(5,1);                      
    for (i=0; i<8; i++)
    {
        gpio_write(4,1);            
        gpio_init(5,0);
        delay_us(5);              
        //gpio_init(5,0);
        dat |= gpio_read(5);         
        if(i<7)
            dat <<= 1;
        gpio_init(5,1);
        gpio_write(4,0);               
        delay_us(5);           
    }
    return dat;
}


void Single_Write_BH1750(int command)
{
    BH1750_Start();                  
    BH1750_SendByte(SlaveAddress);
    BH1750_SendByte(command);
    BH1750_Stop();                   
}

//void Init_BH1750()
//{
//	Single_Write_BH1750(0x01);
//}


int Multiple_Read_BH1750(void)
{
	int temp;
    gpio_BH1750_init();

	Single_Write_BH1750(0x01);  	
	Single_Write_BH1750(0x10);   	
	delay_ms(180);              		

    BH1750_Start();                          
    BH1750_SendByte(SlaveAddress+1);         

	temp = BH1750_RecvByte();
	BH1750_SendACK(0);
	temp = (temp<<8) | BH1750_RecvByte();
	BH1750_SendACK(1);

    BH1750_Stop();                          
    delay_ms(5);
    LX = temp*5/6;
	return LX;   
}


