#include "ls1x.h"
#include "config.h"
#include "ls1x_rtc.h"
#include "ls1x_gpio.h"
#include "ls1x_uart.h"
#include "ls1x_string.h"
#include "ls1x_printf.h"
#include "ls1c102_i2c.h"
#include "ls1c102_adc.h"
#include "ls1x_latimer.h"
#include "ls1c102_ptimer.h"
#include "ls1c102_interrupt.h"

#include "LED.h"
#include "gpio.h"
#include "MQ_2.h"
#include "SHT30.h"
#include "buzzer.h"
#include "BH1750.h"
#include "rtc_test.h"
#include "UserGpio.h"
#include "ESP8266_01s.h"


extern void WDG_DogFeed();
extern tsRtcTime rtc_param;
extern uint8_t receive_buf[];
unsigned char receive_flag=0;//串口
unsigned char flag_bj=0;
unsigned char flag_data=0;
unsigned int BH = 0, Temp = 0, Humi = 0, value=0;

void uart_jieshou_proc();
void printf_Data();
void rtc_collect();
void alarm();

void BH1750_collect()
{
    BH = Multiple_Read_BH1750();
    //printf("%d\n", BH);
}

void SHT30_Get_Temp()
{
    SHT30_Init();
    Temp = SHT30_temp();
    //printf("%d\n", Temp);
}

void SHT30_Get_Humi()
{
    SHT30_Init();
    Humi = SHT30_humi();
    //printf("%d\n", Humi);
}

void MQ_2_Getnum()
{
    MQ_2_Init();
    value=Adc_Measure(ADC_CHANNEL_I0);
    //printf("%d\r\n",value);
}




int main(void)
{
    //rtc_set_time(25, 4, 16, 17, 17, 30);     //设置年月日加时间
    
    timer_init(1);                           //定时器初始化  1--1ms

    gpio_init(63, 1);                        //蜂鸣器初始化
    gpio_write_pin(GPIO_PIN_63, 0);
    
    gpio_init(14, 1);                        //灯光初始化
    gpio_init(20, 1);
    gpio_write_pin(GPIO_PIN_14, 0);
    gpio_write_pin(GPIO_PIN_20, 1);

    gpio_pin_remap(5,0);                     //iic引脚初始化
    gpio_pin_remap(4,0);

    ESP8266_Init();		                     //esp8266进行初始化，连接wifi

   
    while(1)
    {
        WDG_DogFeed();
        
         //rtc_collect();                        //实时时钟
        
        BH1750_collect();                     //光照
        
        SHT30_Get_Temp();                     //温度
        
        SHT30_Get_Humi();                     //湿度
        
        MQ_2_Getnum();                        //烟雾

        ESP_SendData();                       //发送数据
        printf_Data();
        
        alarm();                              //警报
    }
    return 0;
}



void printf_Data()
{
    //printf("1,%d,%d,%d,%d,date:%u/%u/%u--%u:%u:%u\r\n", BH, Temp, Humi, value, rtc_param.year+2000,rtc_param.mon,rtc_param.day,rtc_param.hour,rtc_param.min,rtc_param.sec);
    printf("1,%4d,%3d,%3d,%4d\r\n", BH, Temp, Humi, value);
    delay_ms(500);
}


void rtc_collect()                            //实时时钟采集
{
    RtcUpdateData(1, &rtc_param);
}


void alarm()
{
    if(value >= 800)                     //烟雾阈值
    {
        Buzzer_on();
        LED_on();
    }
    else if(Temp >= 40)                  //温度上阈值
    {
        Buzzer_on();
        LED_on();
    }
    else if(Temp <= 10)                  //温度下阈值
    {
        Buzzer_on();
        LED_on();
    }
    else if(Humi >= 90)                  //湿度上阈值
    {
        Buzzer_on();
        LED_on();
    }
    else if(Humi <= 10)                  //湿度下阈值
    {
        Buzzer_on();
        LED_on();
    }
    else if(BH >= 1000)                  //亮度上阈值
    {
        Buzzer_on();
        LED_on();
    }
    else if(BH <= 10)                    //亮度下阈值
    {
        Buzzer_on();
        LED_on();
    }
    else
    {
        Buzzer_off();
        LED_off();
    }
}


void uart_jieshou_proc()//串口接受处理函数
{
    //if(receive_flag==1)
    //{
        //receive_flag=0;

        //if(strncmp(receive_buf,"CONNECT",7)==0)
        //{
            //memset(receive_buf,0,5);
            
            //LED_on();
            ////printf_Data();//发数据
            //delay_ms(500);
            //flag_data=1;
        //}

        ////if(strncmp(receive_buf,"1ybj",4)==0)//发送TH
        ////{
            ////flag_bj=1;
            ////memset(receive_buf,0,5);

        ////}
        ////else if(strncmp(receive_buf,"1nbj",4)==0)//发送TL
        ////{
            ////flag_bj=0;
            ////memset(receive_buf,0,5);
        ////}
    //}
}

