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
    Adc_powerOn();//adc��Դ����
    Adc_open(ADC_CHANNEL_I0);//��ͨ��0
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

//sfr AUXR=0x8e;//STCӦ�øø����Ĵ���

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
    //PCON &= 0x7F;        //�����ʲ�����
    //SCON = 0x50;        //8λ����,�ɱ䲨����
    //AUXR &= 0xBF;        //��ʱ��ʱ��12Tģʽ
    //AUXR &= 0xFE;        //����1ѡ��ʱ��1Ϊ�����ʷ�����
    //TMOD &= 0x0F;        //���ö�ʱ��ģʽ
    //TMOD |= 0x20;        //���ö�ʱ��ģʽ
    //TL1 = 0xFD;        //���ö�ʱ��ʼֵ
    //TH1 = 0xFD;        //���ö�ʱ����ֵ
    //ET1 = 0;        //��ֹ��ʱ��%d�ж�
    //TR1 = 1;        //��ʱ��1��ʼ��ʱ
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
  //bufsend[0]=0x7f;  //��ʼ�ֽ�
  //bufsend[1]=0x5f;  //�����ߵ�ַ
  //bufsend[2]=0x08;  //�����ߵ�ַ
  //bufsend[3]=3;     //���ݳ���
  //bufsend[4]=0x84;  //����������0x13--->��ȼ���崫����MQ-2
  //bufsend[5]=0;     //ADͨ����P1.0<------>��ȼ���崫����MQ-2��AO
  //bufsend[6]=GetADCResult(0);//ADͨ����0ת��������
  //for(i=1;i<=6;i++)  //���У��������
  //t^=bufsend[i];
  //bufsend[7]=t;     //У���ֽ�
  //bufsend[8]=0xff;  //�����ֽ�
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

