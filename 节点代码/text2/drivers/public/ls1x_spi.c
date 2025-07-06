#include "ls1x_spi.h"
#include "ls1x.h"
#include "Config.h"

/*** SPI READ OPTIONS ***/
#define NORMAL    0x0
#define FAST      0x1
#define DUAL_IO   0x2

/**
 * @Description: SPI ��Ƶϵ������ �ֱ����õ����ƼĴ������ⲿ�Ĵ������������ƼĴ���
 * @Input: ��Ƶϵ��
 * @Output: ��
 * @return {*}��
 * @param {uint8_t} spr ��Ƶϵ��
 */
void Spi_FreqDiv(uint8_t spr)
{

    SPI->SPCR &=0xFC;
    SPI->SPER &=0xFC;

    SPI->SPCR |=(spr & 0x03);
    SPI->SPER |=((spr>>2) & 0x03);

    SPI->PARAM &= 0x02;
    SPI->PARAM |=((spr<<4) & 0xF0);
    printf("\r\n0 SPI->PARAM:%x H \r\n",SPI->PARAM);
}
/**
 * @Description: spi init
 * @Input: spi ��Ƶϵ��
 * SPI_DIV_2 SPI_DIV_4 SPI_DIV_16  SPI_DIV_32  SPI_DIV_8 SPI_DIV_64  SPI_DIV_128
 * SPI_DIV_256 SPI_DIV_512 SPI_DIV_1024 SPI_DIV_2048 SPI_DIV_4096
 * @Output: ��
 * @return {*}
 * @param {uint8_t} spr ��Ƶϵ�� �̶�Ϊ���ϵĺ궨��
 */
void Spi_Init(uint8_t spr)
{
    SPI->SPCR = 0x50; // {int_en, spi, rsvd, mstr, cpol, cpha, spr[1:0]}
    SPI->SPER = 0;
    while(!SPI_TXEMPTY)         ; // wait till tx empty
    while(!SPI_RXEMPTY) SPI->DATA; // read till rx empty
}

/**
 * @Description: spi ����д 1~4�ֽ�
 * @Input: 	���ݻ��壬����д����
 * @Output: ��
 * @return {*}
 * @param {uint8_t*} buf ���ݻ���
 * @param {int} n		��д�����ֽ���
 */
void Spi_Write_Read_1to4(uint8_t* buf, int n)
{

    uint32_t i;
    for (i=0; i<n; i++) SPI->DATA = buf[i];
    while(!SPI_TXEMPTY) ;
    for (i=0; i<n-1; i++) buf[i] = SPI->DATA;
    while(SPI_RXEMPTY) ;
    buf[n-1] = SPI->DATA;
}

/**
 * @Description: spi �� д N�ֽ�
 * @Input: ���ݻ��壬��д�ֽ���
 * @Output: ��
 * @return {*}
 * @param {uint8_t*} buf ���ݻ���
 * @param {int} n	��д�ֽ���
 */
void Spi_Write_Read_N(uint8_t* buf, int n)
{
    uint32_t i, j;
    for (i=0; i<4; i++) SPI->DATA = buf[i];
    for (j=0; i<n; i++, j++)
    {
        while(SPI_RXEMPTY) ;
        buf[j] =  SPI->DATA;
        SPI->DATA = buf[i];
    }
    for (; j<n; j++)
    {
        while(SPI_RXEMPTY) ;
        buf[j] = SPI->DATA;
    }
}

/**
 * @Description: SPI Ƭѡ�ź�0 ʹ�ܲ�����
 * @Input: ��
 * @Output: ��
 * @return {*}
 */
void Spi_Cs_Down(void)
{
    // SPI->SOFTCS = 0xef;

    SPI_ENABLE_CS(1);
    SPI_LOW_CS(1);
}
/**
 * @Description: SPI Ƭѡ�ź�0 ʹ�ܲ�����
 * @Input: ��
 * @Output: ��
 * @return {*}
 */
void Spi_Cs_Up(void)
{
    // SPI->SOFTCS = 0xff;

    SPI_ENABLE_CS(1);
    SPI_HIGH_CS(1);
}

/**
 * @Description: SPI ��������
 * @Input: ���ݻ��壻��������
 * @Output: ��
 * @return {*}
 * @param {uint8_t*} buf ���ݻ���
 * @param {int} n		������
 */
void Spi_Send(uint8_t* buf, int n)
{
    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, n);
    Spi_Cs_Up();
}

/**
 * @Description:
 * @Input:
 * @Output:
 * @return {*}
 */
uint8_t Spiflash_Rdsr(void)
{
    uint8_t buf[4] = {0x05};
    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, 2);
    Spi_Cs_Up();
    return buf[1];
}

/**
 * @Description: �ȴ���0
 * @Input: ��
 * @Output:��
 * @return {*}
 */
void Spiflash_Wait_Wip_Zero(void)
{
    while (Spiflash_Rdsr() & 0x01) {}
}

/**
 * @Description: spi flash д
 * @Input:
 * @Output:
 * @return {*}
 */
void Spiflash_Wren(void)
{
    uint8_t buf[4] = {0x06};

    Spiflash_Wait_Wip_Zero();
    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, 1);
    Spi_Cs_Up();
}

/**
 * @Description: spi flash д�Ĵ���
 * @Input: ״̬
 * @Output: ��
 * @return {*}
 * @param {uint8_t} st ״̬
 */
void Spiflash_Wrsr(uint8_t st)
{
    uint8_t buf[4] = {0x01};

    Spiflash_Wren();
    buf[1] = st;
    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, 2);
    Spi_Cs_Up();
}

/**
 * @Description: spi flash ���Ĵ���2
 * @Input: ��
 * @Output: ���ؼĴ�����ȡ����
 * @return {*}
 */
uint8_t Spiflash_Rdsr2(void)
{
    uint8_t buf[4] = {0x35};

    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, 2);
    Spi_Cs_Up();

    return buf[1];
}

/**
 * @Description: spi flash ���Ĵ���3
 * @Input: ��
 * @Output: ���ض�ȡ��ֵ
 * @return {*}
 */
uint8_t Spiflash_Rdsr3(void)
{
    uint8_t buf[4] = {0x15};

    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, 2);
    Spi_Cs_Up();

    return buf[1];
}

/**
 * @Description: SPI flash �� ID
 * @Input: ��
 * @Output: ����id
 * @return {*}
 */
uint16_t Spiflash_Rdid(void)
{
    uint8_t buf[4] = {0x90, 0, 0, 0};

    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, 4);//trans
    Spi_Write_Read_1to4(buf, 2);//recv
    Spi_Cs_Up();

    return *((uint16_t*)buf);
}

/**
 * @Description: SPI flash ��������
 * @Input:
 * @Output:
 * @return {*}
 * @param {uint32_t} addr
 */
void Spiflash_Sector_Erase(uint32_t addr)
{
    uint8_t buf[4] = {0x20};

    buf[3] = addr & 0xff;
    addr >>= 8;
    buf[2] = addr & 0xff;
    addr >>= 8;
    buf[1] = addr & 0xff;

    Spiflash_Wren();

    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, 4);
    Spi_Cs_Up();
    Spiflash_Wait_Wip_Zero();
}


/**
 * @Description: SPI flash 64k �����
 * @Input: ��ַ
 * @Output: ��
 * @return {*}
 * @param {uint32_t} addr
 */
void Spiflash_Block64k_Erase(uint32_t addr)
{
    uint8_t buf[4] = {0xd8};

    buf[3] = addr & 0xff;
    addr >>= 8;
    buf[2] = addr & 0xff;
    addr >>= 8;
    buf[1] = addr & 0xff;

    Spiflash_Wren();

    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, 4);
    Spi_Cs_Up();
    Spiflash_Wait_Wip_Zero();
}

/**
 * @Description: SPI flash ҳ���
 * @Input: ҳ��ַ�����ݣ�
 * @Output: ��
 * @return {*}
 * @param {uint32_t} addr	ҳ��ַ
 * @param {uint8_t*} data_256	���ݻ���ָ��
 */
void Spiflash_Page_Program(uint32_t addr, uint8_t* data_256,int n)
{
    uint8_t buf[4] = {0x02};

    buf[3] = addr & 0xff;
    addr >>= 8;
    buf[2] = addr & 0xff;
    addr >>= 8;
    buf[1] = addr & 0xff;

    Spiflash_Wren();

    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, 4);
    Spi_Write_Read_N(data_256, n);
    Spi_Cs_Up();
    Spiflash_Wait_Wip_Zero();
}

/**
 * @Description: spi flash ������
 * @Input: ��ַ�����ݻ��壻��������
 * @Output: ��
 * @return {*}
 * @param {uint32_t} addr
 * @param {uint8_t*} data
 * @param {int} n
 */
void Spiflash_Read_Bytes(uint32_t addr, uint8_t* data, int n)
{
    uint8_t buf[4] = {0x03};

    buf[3] = addr & 0xff;
    addr >>= 8;
    buf[2] = addr & 0xff;
    addr >>= 8;
    buf[1] = addr & 0xff;

    Spi_Cs_Down();
    Spi_Write_Read_1to4(buf, 4);
    Spi_Write_Read_N(data, n);
    Spi_Cs_Up();
}






/******************************************************************************
 * �������� SpiTransByte
 * ���ܣ� ͨ��SPI�ӿڴ���һ���ֽ�
 * ���������
 * 		  byte��д���ֽ�
 * ����ֵ��
 *      none
 * ��ע����
 ******************************************************************************/
uint8_t SPI_TransByte(uint8_t byte)
{
    uint8_t ucResult=0;
    uint8_t retry=0;
    /*����жϺ������־λ*/
    SPI->SPSR = 0xc0;

    //�ж�д�Ĵ����Ƿ�Ϊ��
    while(!(SPI->SPSR & 0x04))
    {
        retry++;
        if(retry > 200)
        {
            printf("spi no data send\r\n");
            return 0;
        }
    }
    retry = 0;
    SPI->DATA = byte;
    while(SPI->SPSR & 0x01)
    {
        retry++;
        if(retry > 200)
        {
            printf("spi no data receive\r\n");
            return 0;
        }
    }
    ucResult = SPI->DATA;


    return ucResult;
}

/******************************************************************************
 * �������� SpiFlashCsn0Enable
 * ���ܣ� spi flash csn0 ʹ��
 * ���������
 * 		none
 * ����ֵ��
 *      none
 * ��ע����
 ******************************************************************************/
void SpiFlashCsn0Enable()
{
    /*ʹ��Ƭѡ�ź�CSN0*/
    SPI->SOFTCS = 0xE1;//E1
}

/******************************************************************************
 * �������� SpiFlashCsn0Disable
 * ���ܣ� spi flash csn0 ��ʹ��
 * ���������
 * 		 none
 * ����ֵ��
 *      none
 * ��ע����
 ******************************************************************************/
void SpiFlashCsn0Disable()
{
    /*ʹ��Ƭѡ�ź�CSN0*/
    SPI->SOFTCS = 0xF1;
}

