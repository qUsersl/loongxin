/*
 * SHT30.c
 *
 * created: 2025/4/7
 *  author: 
 */

#include "config.h"
#include "SHT30.h"

extern void gpio_init(unsigned char gpio,unsigned char io);
extern void gpio_write(unsigned char gpio,unsigned char val);
extern unsigned char gpio_read(unsigned char gpio);
extern void delay_us(unsigned int us);
extern void delay_ms(unsigned int ms);

#define SHT30_ADDR_WRITE 0x88
#define SHT30_ADDR_READ 0x89


unsigned char CY;

void gpio_SHT30_init(void)
{
    gpio_init(5,1);
    gpio_init(4,1);
}

/*================================================================
���� �ơ�void SHT30_Start()
���� �ܡ�I2C��ʼ�ź�
���� ע��SCL��SDAͬΪ�ߣ�SDA����ɵ�֮��SCL����ɵ�
================================================================*/
void SHT30_Start()
{
    gpio_write(5,1);
    gpio_write(4,1);
    delay_us(5);
    gpio_write(5,0);
    delay_us(10);
    gpio_write(4,0);
    delay_us(5);
}

/*================================================================
���� �ơ�void SHT30_Stop()
���� �ܡ�I2Cֹͣ�ź�
���� ע��SCL��SDAͬΪ�ͣ�SCL����ɸ�֮��SDA����ɸ�
================================================================*/
void SHT30_Stop()
{
    gpio_write(5,0);
    delay_us(5);
    gpio_write(4,1);
    delay_us(5);
    gpio_write(5,1);
}

/*================================================================
���� �ơ�void SHT30_SendACK()
���� �ܡ�����ACK����ź�
���� ע��
================================================================*/
void SHT30_SendACK()
{
    gpio_write(5,0);
    delay_us(5);
    gpio_write(4,1);
    delay_us(5);
    gpio_write(4,0);
    delay_us(5);
    gpio_write(5,1);
    delay_us(5);
}

unsigned char SHT30_RecvACK()
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

/*================================================================
���� �ơ�void SHT30_SendByte(unsigned char dat)
���� �ܡ�I2Cдһ���ֽ�����
���� ע���Ӹߵ��ͣ����η���
================================================================*/
void SHT30_SendByte(unsigned char dat)
{
    unsigned int i;

    for (i=0; i<8; i++)
    {
        if((dat&0x80)==0x80)
            CY=1;
        else CY=0;
        gpio_write(5,CY);
        delay_us(5);
        gpio_write(4,1);     //���SDA�ȶ�������SCL���������أ��ӻ���⵽��������ݲ���
        delay_us(5);
        gpio_write(4,0);
        delay_us(5);
        dat <<= 1;
    }
    SHT30_RecvACK();
}

/*================================================================
���� �ơ�unsigned char SHT30_ReadByte()
���� �ܡ�I2C��һ���ֽ�����
���� ע���Ӹߵ��ͣ����ν���
================================================================*/
unsigned char SHT30_ReadByte()
{
    unsigned int i;
    unsigned char dat;

    gpio_write(4,0);
    gpio_write(5,1);      //�ͷ�����
    
    for (i=0; i<8; i++)
    {
        dat <<= 1;           //��λ
        gpio_write(4,1);     //����������
        delay_us(5);         //��ʱ�ȴ��ź��ȶ�
        dat |= gpio_read(5); //������ȡ����
        gpio_write(4,0);
        delay_us(5);
    }
    return dat;
}

/*================================================================
���� �ơ�void SHT3XInit(void)
���� �ܡ�SHT3X��ʼ���������������е���
================================================================*/
void SHT30_Init()
{
    gpio_SHT30_init();
    
    SHT30_Start();
    SHT30_SendByte(SHT30_ADDR_WRITE);
    SHT30_SendByte(0x20);
    SHT30_SendByte(0x32);
    SHT30_Stop();
    delay_ms(50);
}

int SHT30_temp(void)
{
    unsigned char temp_h, temp_l, crc1, humi_h, humi_l, crc2;
    int temp;

    SHT30_Start();
    SHT30_SendByte(SHT30_ADDR_WRITE);  // ��������д��ַ
    SHT30_SendByte(0xE0);  // ѡ��ʼ��ʪ�Ȳ�������
    SHT30_SendByte(0x00);
    SHT30_Stop();

    delay_ms(260);    // ��ʱ�ȴ���ʪ�Ȳ������

    SHT30_Start();
    SHT30_SendByte(SHT30_ADDR_READ);  // �������Ͷ���ַ
    temp_h = SHT30_ReadByte();
    SHT30_SendACK();
    temp_l = SHT30_ReadByte();
    SHT30_SendACK();
    crc1 = SHT30_ReadByte();
    SHT30_SendACK();
    humi_h = SHT30_ReadByte();
    SHT30_SendACK();
    humi_l = SHT30_ReadByte();
    SHT30_SendACK();
    crc2 = SHT30_ReadByte();
    SHT30_Stop();

    temp = ((temp_h<<8) | temp_l)*175/65535 - 45; // �¶�ֵת����ʽ

    return temp;
}

int SHT30_humi(void)
{
    unsigned char temp_h, temp_l, crc1, humi_h, humi_l, crc2;
    int humi;

    SHT30_Start();
    SHT30_SendByte(SHT30_ADDR_WRITE);  // ��������д��ַ
    SHT30_SendByte(0xE0);  // ѡ��ʼ��ʪ�Ȳ�������
    SHT30_SendByte(0x00);
    SHT30_Stop();

    delay_ms(260);    // ��ʱ�ȴ���ʪ�Ȳ������

    SHT30_Start();
    SHT30_SendByte(SHT30_ADDR_READ);  // �������Ͷ���ַ
    temp_h = SHT30_ReadByte();
    SHT30_SendACK();
    temp_l = SHT30_ReadByte();
    SHT30_SendACK();
    crc1 = SHT30_ReadByte();
    SHT30_SendACK();
    humi_h = SHT30_ReadByte();
    SHT30_SendACK();
    humi_l = SHT30_ReadByte();
    SHT30_SendACK();
    crc2 = SHT30_ReadByte();
    SHT30_Stop();
    
    humi = ((humi_h<<8) | humi_l)*100/65535; // ʪ��ֵת����ʽ

    return humi;
}

