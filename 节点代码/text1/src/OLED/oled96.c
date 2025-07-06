#include "oled96.h"
#include "oled_font.h"
#include "ls1c102_i2c.h"
#include "ls1x_latimer.h"
#include "ls1x.h"
#include "ls1x_gpio.h"
#include "ls1x_wdg.h"

//extern HW_PMU_t *g_pmu;

//  VCC     �� 3.3v ��Դ
//  GND     ��Դ��
//  SCL     GPIO4 ��ʱ�ӣ�
//  SDA     GPIO5 �����ݣ�

// ==========================================================================
// OLED���Դ��Ÿ�ʽ����
// [0]0 1 2 3 ... 127
// [1]0 1 2 3 ... 127
// [2]0 1 2 3 ... 127
// [3]0 1 2 3 ... 127
// [4]0 1 2 3 ... 127
// [5]0 1 2 3 ... 127
// [6]0 1 2 3 ... 127
// [7]0 1 2 3 ... 127

/*
    �� OLED д��һ���ֽڵ�����0xFF���õ��������е�8�����㡣
    �� OLED д��һ���ֽڵ�����0xF0���õ�����4λ�͵İ��㣬����4λ�ߵ����㡣
    ˵�� OLED ��ʾ���������еģ��ϵ��¸ߡ�

    ʹ��Ӳ�� I2C ����һ���ֽڣ�Ĭ�����ȷ��͸�λ���ٷ��͵�λ��
    OLED ����һ���ֽں��ա�����ʽ����ʾ��������ʽ���������ң����ϵ��£�ÿ���ֽ�����8λ����λ���ϡ�
    ������յ�0xF0 0x0F����ô��Ӧ�� OLED ��ʾΪ
    0 1
    0 1
    0 1
    0 1
    1 0
    1 0
    1 0
    1 0
*/

/*

*/
void I2C_delay(void)
{
    for(volatile int j = 200; j; j--){
        ;
    }
}

// ==========================================================================
//��I2C�豸��������
void Write_IIC_Command(uint8_t IIC_Command)
{
    I2C_GenerateSTART(I2C,ENABLE);  // ����������ʼ�źţ���ʾ��ʼ�������ݡ�

    I2C_SendData(I2C,OLED_I2C_ADR); // ����I2C�豸�ĵ�ַ����ʾҪ�������ݸ����豸
    I2C_wait(I2C);                 //�����ȴ��������

    I2C_SendData(I2C,0x00);         // �����������ͣ�һ����0x00��ʾд�����
    I2C_wait(I2C);
    
    I2C_SendData(I2C,IIC_Command);  //���;��������ֵ��
    I2C_wait(I2C);
    
    I2C_GenerateSTOP(I2C,ENABLE);  //����ֹͣ�źţ���ʾ�������
}


// ==========================================================================
//I2C�豸��������
void Write_IIC_Data(uint8_t IIC_Data)
{
    I2C_GenerateSTART(I2C,ENABLE);  //������ʼ�źţ���ʾ��ʼ��������
    
    I2C_SendData(I2C,OLED_I2C_ADR); // ����I2C�豸�ĵ�ַ����ʾҪ�������ݸ����豸
    I2C_wait(I2C);                  //�����ȴ��������
    
    I2C_SendData(I2C,0x40);
    I2C_wait(I2C);
    
    I2C_SendData(I2C,IIC_Data);
    I2C_wait(I2C);
    
    I2C_GenerateSTOP(I2C,ENABLE);
    I2C_wait(I2C);
}

// ==========================================================================
//��OLED��ʾ��д���ֽ�����
//����dat��ʾҪд����ֽ�����
void OLED_WR_Byte(uint8_t dat, uint8_t cmd)
{
    if(cmd)
    {
        Write_IIC_Data(dat);   //cmdΪ1����д���������ͣ�����Write_IIC_Data������
    }
    else
    {
        Write_IIC_Command(dat); //cmdΪ0����д���������ͣ�����Write_IIC_Command����
    }
}

// ==========================================================================
// ��ʼ��Һ��ģ��
void OLED_Init(void)
{
    OLED_WR_Byte(0xAE, OLED_CMD);    // --turn off oled panel
    delay_ms(10);
    OLED_WR_Byte(0x00, OLED_CMD);    // --set low column address
    delay_ms(10);
    OLED_WR_Byte(0x10, OLED_CMD);    // ---set high column address
    delay_ms(10);
    OLED_WR_Byte(0x40, OLED_CMD);    // --set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
    delay_ms(10);
    OLED_WR_Byte(0x81, OLED_CMD);    // --set contrast control register
    delay_ms(10);
    OLED_WR_Byte(0xCF, OLED_CMD);    // Set SEG Output Current Brightness
    delay_ms(10);
    OLED_WR_Byte(0xA1, OLED_CMD);    // --Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
    delay_ms(10);
    OLED_WR_Byte(0xC8, OLED_CMD);    // Set COM/Row Scan Direction   0xc0���·��� 0xc8����
    delay_ms(10);
    OLED_WR_Byte(0xA6, OLED_CMD);    // --set normal display
    delay_ms(10);
    OLED_WR_Byte(0xA8, OLED_CMD);    // --set multiplex ratio(1 to 64)
    delay_ms(10);
    OLED_WR_Byte(0x3f, OLED_CMD);    // --1/64 duty
    delay_ms(10);
    OLED_WR_Byte(0xD3, OLED_CMD);    // -set display offset    Shift Mapping RAM Counter (0x00~0x3F)
    delay_ms(10);
    OLED_WR_Byte(0x00, OLED_CMD);    // -not offset
    delay_ms(10);
    OLED_WR_Byte(0xd5, OLED_CMD);    // --set display clock divide ratio/oscillator frequency
    delay_ms(10);
    OLED_WR_Byte(0x80, OLED_CMD);    // --set divide ratio, Set Clock as 100 Frames/Sec
    delay_ms(10);
    OLED_WR_Byte(0xD9, OLED_CMD);    // --set pre-charge period
    delay_ms(10);
    OLED_WR_Byte(0xF1, OLED_CMD);    // Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
    delay_ms(10);
    OLED_WR_Byte(0xDA, OLED_CMD);    // --set com pins hardware configuration
    delay_ms(10);
    OLED_WR_Byte(0x12, OLED_CMD);
    delay_ms(10);
    OLED_WR_Byte(0xDB, OLED_CMD);    // --set vcomh
    delay_ms(10);
    OLED_WR_Byte(0x40, OLED_CMD);    // Set VCOM Deselect Level
    delay_ms(10);
    OLED_WR_Byte(0x20, OLED_CMD);    // -Set Page Addressing Mode (0x00/0x01/0x02)
    delay_ms(10);
    OLED_WR_Byte(0x02, OLED_CMD);    //
    delay_ms(10);
    OLED_WR_Byte(0x8D, OLED_CMD);    // --set Charge Pump enable/disable
    delay_ms(10);
    OLED_WR_Byte(0x14, OLED_CMD);    // --set(0x10) disable
    delay_ms(10);
    OLED_WR_Byte(0xA4, OLED_CMD);    //  Disable Entire Display On (0xa4/0xa5)
    delay_ms(10);
    OLED_WR_Byte(0xA6, OLED_CMD);    //  Disable Inverse Display On (0xa6/a7)
    delay_ms(10);
    OLED_WR_Byte(0xAF, OLED_CMD);    // --turn on oled panel
    delay_ms(10);
}

// ==========================================================================
void OLED_Clear(void)
{
    uint8_t i, n;
    for(i = 0; i < 8; i++)// 8�У�ÿ��16���ֽڣ�ÿ���ֽ���������
    {
        OLED_WR_Byte(0xb0 + i, OLED_CMD);  //����ҳ��ַ��0~7��
        OLED_WR_Byte(0x00, OLED_CMD);      //������ʾλ�á��е͵�ַ
        OLED_WR_Byte(0x10, OLED_CMD);      //������ʾλ�á��иߵ�ַ
        for(n = 0; n < 128; n++)
        {
            OLED_WR_Byte(0, OLED_DATA);// ƽ��0.075s ��
        }
    }
}

// ==========================================================================
void OLED_Full(void)
{
    uint8_t i, n;
    for(i = 0; i < 8; i++)// 8�У�ÿ��16���ֽڣ�ÿ���ֽ���������
    {
        OLED_WR_Byte(0xb0 + i, OLED_CMD);  //����ҳ��ַ��0~7��
        OLED_WR_Byte(0x00, OLED_CMD);      //������ʾλ�á��е͵�ַ
        OLED_WR_Byte(0x10, OLED_CMD);      //������ʾλ�á��иߵ�ַ
        for(n = 0; n < 128; n++)
        {
            OLED_WR_Byte(0xff, OLED_DATA);
        }
    }
}

// ==========================================================================
// ����OLED��ʾ
void OLED_Display_On(void)
{
    OLED_WR_Byte(0X8D, OLED_CMD);  // SET DCDC ����
    OLED_WR_Byte(0X14, OLED_CMD);  // DCDC ON
    OLED_WR_Byte(0XAF, OLED_CMD);  // DISPLAY ON
}

// ==========================================================================
// �ر�OLED��ʾ
void OLED_Display_Off(void)
{
    OLED_WR_Byte(0X8D, OLED_CMD);  // SET DCDC ����
    OLED_WR_Byte(0X10, OLED_CMD);  // DCDC OFF
    OLED_WR_Byte(0XAE, OLED_CMD);  // DISPLAY OFF
}

// ==========================================================================
void OLED_Set_Pos(uint8_t x, uint8_t y)
{
	//OLED_WR_Byte(0xb0 + y / 8, OLED_CMD);// �������Ա���Ϊ��λ��0~112
	OLED_WR_Byte(0xb0 + y, OLED_CMD);// ���������ֽ�Ϊ��λ��0~7
	OLED_WR_Byte((((x) & 0xf0)>>4) | 0x10, OLED_CMD);
	OLED_WR_Byte(((x) & 0x0f), OLED_CMD);
}

// ==========================================================================
// ��ָ��λ����ʾһ���ַ������������ַ�
// x: 0~127
// y: 0~63
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr)
{
    uint8_t c = 0, i = 0;
    c = chr - ' ';// �õ�ƫ�ƺ��ֵ
    if(x > 120)
    {
        x = 0;
        y = y + 2;
    }
    if(y > 6)
    {
        y = 0;
    }
    if(SIZE == 16)// ��Ϊ��16*8�������Ƽ� x = {0 8 16 ... 112 120}, y = {0 16 32 48}
    {
        OLED_Set_Pos(x, y);
        for(i = 0; i < 8; i++)
            OLED_WR_Byte(Char_Font_16x8[c][i], OLED_DATA);
        //OLED_Set_Pos(x, y + 8);
        OLED_Set_Pos(x, y + 1);
        for(i = 0; i < 8; i++)
            OLED_WR_Byte(Char_Font_16x8[c][i + 8], OLED_DATA);
    }
}

// m^n����
uint32_t oled_pow(uint8_t m, uint8_t n)
{
    uint32_t result = 1;
    while(n--)
        result *= m;
    return result;
}

// ==========================================================================
// ��ʾ����
// x, y : �������
// num : ��ֵ(0~4294967295);
// len : ���ֵ�λ��
// size: �����С
void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size)
{
    uint8_t t, temp;
    uint8_t enshow = 0;
    for(t = 0; t < len; t++)
    {
        if(x > 120)
        {
            x = 0;y = y + 2;
        }
        if(y > 6)
        {
            y = 0;
        }
        temp = (num / oled_pow(10, len - t - 1)) % 10;
        if(enshow == 0 && t < (len - 1))
        {
            if(temp == 0)
            {
                OLED_ShowChar(x, y, ' ');
                x += (size / 2);
                continue;
            }
            else
                enshow = 1;
        }
        OLED_ShowChar(x, y, temp + '0');
        x += (size / 2);
    }
}

// ==========================================================================
// ��ʾ�ַ���
void OLED_ShowString(uint8_t x, uint8_t y, char *chr)
{


    uint8_t j = 0;
    while (chr[j] != '\0')
    {
        if(x > 120)
        {
            x = 0;y += 2;
        }
        if(y > 6)
        {
            y = 0;
        }
        OLED_ShowChar(x, y, chr[j]);
        j++;
        x += 8;
    }
}

// ==========================================================================
// ��ʾһ�� 16*16 ������ַ������֣�
void OLED_ShowCHinese(uint8_t x, uint8_t y, uint8_t num)
{
    //OLED_WR_Byte(0x02, OLED_DATA);
    if(x > 120)
    {
        x = 0;y += 2;
    }
    if(y > 6)
    {
        y = 0;
    }
    OLED_Set_Pos(x, y);
    for(int t = 0;t < 16; t++)
    {
        OLED_WR_Byte(Chi_Cha_Font_16x16[2 * num][t], OLED_DATA);
    }
    OLED_Set_Pos(x, y + 1);
    for(int t = 0; t < 16; t++)
    {
        OLED_WR_Byte(Chi_Cha_Font_16x16[2 * num + 1][t], OLED_DATA);
    }
    //delay_ms(10);
}

