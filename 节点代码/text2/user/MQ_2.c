/*
 * MQ_2.c
 *
 * created: 2025/4/8
 *  author: 
 */


#include "config.h"
#include "MQ_2.h"
#include "ls1c102_adc.h"

//extern void gpio_init(unsigned char gpio,unsigned char io);
//extern void gpio_write(unsigned char gpio,unsigned char val);
//extern unsigned char gpio_read(unsigned char gpio);
//extern void delay_us(unsigned int us);
//extern void delay_ms(unsigned int ms);

//int value=0;

void MQ_2_Init()
{
    Adc_powerOn();//adc电源开启
    Adc_open(ADC_CHANNEL_I0);//打开通道0
}

//void MQ_2_Getnum()
//{
    //value=Adc_Measure(ADC_CHANNEL_I0);
    //printf("%d\r\n",value);
    //delay_ms(1000);
//}


//#include "reg51.h"
//#include "intrins.h"

//#define UPID 0X6F
//#define MYID 0x08

//sfr AUXR=0x8e;//STC应用该辅助寄存器

/*Declare SFR associated with the ADC*/
//sfr ADC_CONTR = 0xBC;  //ADC control register
//sfr ADC_RES = 0xBD;     //ADC high 8-bit result register
//sfr ADC_LOW2 = 0xBE;    //ADC low 2-bit result register
//sfr P1ASF = 0x9D;       //P1 secondary function control register


/*Define ADC operation const for ADC_CONTR*/
//#define ADC_POWER  0x80     //ADC power control bit
//#define ADC_FLAG   0x10     //ADC complete flag
//#define ADC_START  0x08     //ADC start control bit
//#define ADC_SPEEDLL 0x00    //420 clocks
//#define ADC_SPEEDL 0x20     //280 clocks
//#define ADC_SPEEDH  0x40      //140 clocks
//#define ADC_SPEEDHH 0x60    //70 clocks

//unsigned char bufsend[10];


//void Delay1ms(unsigned int x)   //@11.0592MHz
//{
   //unsigned char i,j;
     //while(x--)
   //{
     //_nop_();
         //i= 11;
         //j= 190;
         //do
             //{
         //while(--j);
             //}
             //while(--i);
   //}
//}

//void UartInit(void)        //9600bps@11.0592MHz
//{
    //PCON &= 0x7F;        //波特率不倍速
    //SCON = 0x50;        //8位数据,可变波特率
    //AUXR &= 0xBF;        //定时器时钟12T模式
    //AUXR &= 0xFE;        //串口1选择定时器1为波特率发生器
    //TMOD &= 0x0F;        //设置定时器模式
    //TMOD |= 0x20;        //设置定时器模式
    //TL1 = 0xFD;        //设置定时初始值
    //TH1 = 0xFD;        //设置定时重载值
    //ET1 = 0;        //禁止定时器%d中断
    //TR1 = 1;        //定时器1开始计时
//}


//void InitADC()
//{
  //P1ASF = 0x01;     //Open 8 channels ADC function
  //ADC_RES =0;       //Clear previous result
  //ADC_CONTR=ADC_POWER | ADC_SPEEDLL;
  //Delay1ms(2);      //ADC power-on and delay
//}

//unsigned char GetADCResult(unsigned char ch)
    //{
    //ADC_CONTR=ADC_POWER | ADC_SPEEDLL| ch | ADC_START;
        //_nop_();       //Must wait before inquiry
    //_nop_();
    //_nop_();
        //_nop_();
    //while(!(ADC_CONTR & ADC_FLAG));   //Wait complete flag
        //ADC_CONTR &=~ADC_FLAG;     //Close ADC
    //return ADC_RES;           //Return ADC result
  //}


//unsigned char DataSendPreprocess()
//{
  //unsigned char i,t=0;
  //bufsend[0]=0x7f;  //起始字节
  //bufsend[1]=0x5f;  //接受者地址
  //bufsend[2]=0x08;  //发送者地址
  //bufsend[3]=3;     //数据长度
  //bufsend[4]=0x84;  //传感器类型0x13--->可燃气体传感器MQ-2
  //bufsend[5]=0;     //AD通道号P1.0<------>可燃气体传感器MQ-2的AO
  //bufsend[6]=GetADCResult(0);//AD通道号0转换后数据
  //for(i=1;i<=6;i++)  //异或校验码生成
  //t^=bufsend[i];
  //bufsend[7]=t;     //校验字节
  //bufsend[8]=0xff;  //结束字节
  //return 9;
//}

//void DataSend(unsigned char ss[],unsigned char len)
    //{
    //unsigned char i;
        //for(i=0;i<len;i++)
        //{
      //SBUF=ss[i];
          //while(TI==0);
      //TI=0;
    //}
  //}
//void main()
    //{
    //unsigned char len;
        //InitADC();
    //UartInit();
    //while(1)
            //{
        //len=DataSendPreprocess();
                //DataSend(bufsend,len);
                //Delay1ms(1000);
      //}
  //}

