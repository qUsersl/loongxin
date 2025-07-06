#ifndef _LS1X_H_
#define _LS1X_H_

#include "test.h"

/*****************************************************/
/******************  NORMAL ADDRESS SPACE  ******************/
#if defined(LS1C102)
#define UNCACHED_MEMORY_ADDR 	0xa0000000
#define UNCACHED_TO_PHYS(x)     ((x) & 0x1fffffff)
#define PHYS_TO_UNCACHED(x)     ((x) | UNCACHED_MEMORY_ADDR)
#define RAM0_BASE			    PHYS_TO_UNCACHED(0x00000000)            //iram
#define RAM1_BASE			    PHYS_TO_UNCACHED(0x00001000)            //dram
#define SPI_MEM_BASE			PHYS_TO_UNCACHED(0x1e000000)            //spi_flash
#define FLASH_MEM_BASE   		PHYS_TO_UNCACHED(0x1f000000)            //on-chip flash
#define FLASH_BASE		        PHYS_TO_UNCACHED(0x1fe60000)            //flash regs
#define SPI_BASE	        	PHYS_TO_UNCACHED(0x1fe70000)            //spi regs
#define UART0_BASEADDR  		PHYS_TO_UNCACHED(0x1fe80000)            //uart0
#define UART1_BASEADDR			PHYS_TO_UNCACHED(0x1fe88000)            //uart1
#define UART2_BASEADDR			PHYS_TO_UNCACHED(0x1fe8c000)            //uart2
#define I2C_BASE			    PHYS_TO_UNCACHED(0x1fe90000)            //i2c
#define INTC_BASE			    PHYS_TO_UNCACHED(0x1fea0000)            //Interrupt_Regs_Baseadd
#define PMU_BASE			    PHYS_TO_UNCACHED(0x1feb0000)            //PMU
#define TSENSOR_BASE		    PHYS_TO_UNCACHED(0x1feb4000)            //tsensor
#define RTC_BASE			    PHYS_TO_UNCACHED(0x1feb8000)            //rtc
#define DMA_BASE		        PHYS_TO_UNCACHED(0x1fec0000)            //DMA
#define VPWM_BASE		        PHYS_TO_UNCACHED(0x1fec0020)            //vpwm
#define TIMER_BASE		        PHYS_TO_UNCACHED(0x1fed0000)            //timer

#define ATE_Freq			   (*(volatile int *)0xbf0201b0)


/******************  PMU REGS  ******************/
typedef struct
{
    volatile uint32_t CHIPCTRL;
    volatile uint32_t CMDSTS;
    volatile uint32_t COUNT;
    volatile uint32_t COMPARE;
    volatile uint32_t IOSEL0;
    volatile uint32_t IOSEL1;
    volatile uint32_t IOSEL2;
    volatile uint32_t IOSEL3;
    volatile uint32_t EXTINT_EN;
    volatile uint32_t EXINT_POL;
    volatile uint32_t EXINT_EDGE;
    volatile uint32_t EXINT_SRC;
    volatile uint32_t WDT_CFG;
    volatile uint32_t WDT_FEED;
    volatile uint32_t POWER_CFG;
    volatile uint32_t CMDW;
    volatile uint32_t GPIOA_OE;
    volatile uint32_t GPIOA_O;
    volatile uint32_t GPIOA_I;
    volatile uint32_t RESERVED0;
    volatile uint32_t GPIOB_OE;
    volatile uint32_t GPIOB_O;
    volatile uint32_t GPIOB_I;
    volatile uint32_t RESERVED1;
    volatile uint32_t PULSE0;
    volatile uint32_t PULSE1;
    volatile uint32_t USER_DAT0;
    volatile uint32_t ADC_CTRL;
    volatile uint32_t ADC_DAT;
} PMU_TypeDef;

#define PMU_ChipCtrl               0x00
#define PMU_Command                0x04
#define PMU_Count                  0x08
#define PMU_Compare                0x0c
#define PMU_WdtCfg                 0x30
#define PMU_WdtFeed                0x34
#define PMU_PowerCfg               0x38
#define PMU_CommandW               0x3c
#define PMU_GPIOAOE_OFFSET         0x40
#define PMU_GPIOAO_OFFSET          0x44
#define PMU_GPIOAI_OFFSET          0x48
#define PMU_GPIOBOE_OFFSET         0x50
#define PMU_GPIOBO_OFFSET          0x54
#define PMU_GPIOBI_OFFSET          0x58
#define PMU_PULSE0_OFFSET          0x60
#define PMU_PULSE1_OFFSET          0x64
#define PMU_ADCCTRL_OFFSET         0x6c
#define PMU_ADCDAT_OFFSET          0x70
//PMU access by 8-bit
#define PMU_GPIOBIT_OFFSET         0x80
#define PMU_SoftRst		           0x10
#define PMU_ClkOff		           0x14
#define PMU_SrProt		           0x18
#define PMU_UserDat1		       0x64
#define PMU_UserDat2		       0x68
#define PMU_UserDat3		       0x6c
/******************  GPIO REGS  ******************/
typedef struct
{
    volatile uint32_t IOSEL;
} AFIO_TypeDef;

typedef struct
{
    volatile uint32_t GPIO_OE;                    /* GPIO���ʹ�ܼĴ��� */
    volatile uint32_t GPIO_O;                             /* GPIO�����ƽ�Ĵ��� */
    volatile uint32_t GPIO_I;                             /* GPIO�����ƽ�Ĵ��� */
} GPIO_TypeDef;

#define PMU_UserDat0               0x68
#define AFIO_Sela  		           0x10
#define AFIO_Selb                  0x14
#define AFIO_Selc                  0x18
#define AFIO_Seld                  0x1c
#define EXTI_En 	               0x20
#define EXTI_Pol                   0x24
#define EXTI_Edge                  0x28
#define EXTI_Src                   0x2c

#define PMU_CHIPCTRL  	       *(volatile unsigned int *)(PMU_BASE+0x00)    //ȫ������
#define PMU_CMDSTS  	       *(volatile unsigned int *)(PMU_BASE+0x04)    //������״̬
#define PMU_COUNT   	       *(volatile unsigned int *)(PMU_BASE+0x08)    //ʱ�������
#define PMU_COMPARE  	       *(volatile unsigned int *)(PMU_BASE+0x0c)    //����ʱ������
#define AFIO_PORTA	           *(volatile unsigned int *)(PMU_BASE+0x10)    //IO����ѡ��0
#define AFIO_PORTB	           *(volatile unsigned int *)(PMU_BASE+0x14)    //IO����ѡ��1
#define AFIO_PORTC	           *(volatile unsigned int *)(PMU_BASE+0x18)    //IO����ѡ��2
#define AFIO_PORTD	           *(volatile unsigned int *)(PMU_BASE+0x1c)    //IO����ѡ��3
#define EXTI_EN 	           *(volatile unsigned int *)(PMU_BASE+0x20)    //�ⲿ�ж�ʹ��
#define EXTI_POL               *(volatile unsigned int *)(PMU_BASE+0x24)    //�ⲿ�жϼ���
#define EXTI_EDGE              *(volatile unsigned int *)(PMU_BASE+0x28)    //�ⲿ�жϱ���
#define EXTI_SRC               *(volatile unsigned int *)(PMU_BASE+0x2c)    //�ⲿ�ж�״̬
#define PMU_WDTCFG             *(volatile unsigned int *)(PMU_BASE+0x30)    //���Ź�����
#define PMU_WDTFEED            *(volatile unsigned int *)(PMU_BASE+0x34)    //���Ź�����
#define PMU_POWERCFG 	       *(volatile unsigned int *)(PMU_BASE+0x38)    //��Դ����
#define PMU_GPIOA_OE 	       *(volatile unsigned int *)(PMU_BASE+0x40)    //GPIOA���ʹ��
#define PMU_GPIOA_O	           *(volatile unsigned int *)(PMU_BASE+0x44)    //GPIOA�����ƽ
#define PMU_GPIOA_I	           *(volatile unsigned int *)(PMU_BASE+0x48)    //GPIOA�����ƽ
#define PMU_GPIOB_OE 	       *(volatile unsigned int *)(PMU_BASE+0x50)    //GPIOB���ʹ��
#define PMU_GPIOB_O	           *(volatile unsigned int *)(PMU_BASE+0x54)    //GPIOB�����ƽ
#define PMU_GPIOB_I	           *(volatile unsigned int *)(PMU_BASE+0x58)    //GPIOB�����ƽ
#define PMU_Pulse0 	           *(volatile unsigned int *)(PMU_BASE+0x60)    //�����������0
#define PMU_Pulse1 	           *(volatile unsigned int *)(PMU_BASE+0x64)    //�����������1
#define PMU_UserDAT            *(volatile unsigned int *)(PMU_BASE+0x68)    //�û�����
#define PMU_AdcCtrl 	       *(volatile unsigned int *)(PMU_BASE+0x6c)    //ADC����
#define PMU_AdcDat  	       *(volatile unsigned int *)(PMU_BASE+0x70)    //ADC����
#define PMU_GPIOBit(i) 	       *(volatile unsigned char *)(PMU_BASE+0x80+i) //GPIOλ����
#define PMU_CMDW               *(volatile unsigned int *) (PMU_BASE+0x3c)   //Commandд�˿�



#define AFIOA_BASE	(PMU_BASE + AFIO_Sela)
#define AFIOB_BASE	(PMU_BASE + AFIO_Selb)
#define AFIOC_BASE	(PMU_BASE + AFIO_Selc)
#define AFIOD_BASE	(PMU_BASE + AFIO_Seld)
#define GPIOA_BASE	(PMU_BASE + 0x40)
#define GPIOB_BASE	(PMU_BASE + 0x50)

#define PMU	        ((PMU_TypeDef *) PMU_BASE)
#define AFIOA		((AFIO_TypeDef *) AFIOA_BASE)
#define AFIOB		((AFIO_TypeDef *) AFIOB_BASE)
#define AFIOC		((AFIO_TypeDef *) AFIOC_BASE)
#define AFIOD		((AFIO_TypeDef *) AFIOD_BASE)
#define GPIOA		((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB		((GPIO_TypeDef *) GPIOB_BASE)

/******************  INTC REGS  ******************/
typedef struct
{
    volatile uint8_t INTC_EN;					/* �ж�ʹ�ܼĴ��� */
    volatile uint8_t INTC_EDGE;				/* �жϱ��ؼĴ��� */
    volatile uint8_t INTC_POL;					/* �жϼ��ԼĴ��� */
    volatile uint8_t INTC_CLR;					/* �ж�����Ĵ��� */
    volatile uint8_t INTC_SET;					/* �ж���λ�Ĵ��� */
    volatile uint8_t INTC_OUT;					/* �ж�����Ĵ��� */
    volatile uint8_t SRPRPT;					/* ����״̬�������Ĵ��� */
} INT_TypeDef;

#define INTC_EN_OFFSET             0x0
#define INTC_EDGE_OFFSET           0x1
#define INTC_POL_OFFSET            0x2
#define INTC_CLR_OFFSET            0x3
#define INTC_SET_OFFSET            0x4
#define INTC_OUT_OFFSET            0x5
#define INTC_SRPROT_OFFSET         0x6
#define INTC_CKGATE_OFFSET         0x7
#define INT_EN	               *(volatile unsigned char *)(INTC_BASE+0x00)     //�ж�ʹ�ܼĴ���
#define INT_EGDE               *(volatile unsigned char *)(INTC_BASE+0x01)     //�жϱ��ؼĴ���
#define INT_POL                *(volatile unsigned char *)(INTC_BASE+0x02)     //�жϼ��ԼĴ���
#define INT_CLR                *(volatile unsigned char *)(INTC_BASE+0x03)     //�ж�����Ĵ���
#define INT_SET                *(volatile unsigned char *)(INTC_BASE+0x04)     //�ж���λ�Ĵ���
#define INT_OUT                *(volatile unsigned char *)(INTC_BASE+0x05)     //�ж�����Ĵ���
#define INT_SRPROT             *(volatile unsigned char *)(INTC_BASE+0x06)     //����״̬�������Ĵ�

#define SRPROT	INT_SRPROT
#define INT					((INT_TypeDef *) INTC_BASE)


/******************  UART REGS  ******************/
typedef struct
{
    volatile uint8_t DAT_DL_L ;			/* �������ݼĴ��� �� ��Ƶֵ���ֽڼĴ��� */
    volatile uint8_t IER_DL_H;			/* �ж�ʹ�ܼĴ��� �� ��Ƶֵ���ֽڼĴ��� */
    volatile uint8_t IIR_FCR_DL_D;		/* �ж�״̬�Ĵ棨ֻ���� FIFO���ƼĴ��� ��ֻд��  ��   ��ƵֵС���Ĵ���  */
    volatile uint8_t LCR;					/* ��·���ƼĴ���  */
    volatile uint8_t SAMPLE_CTRL;				/* bit���ڻ��ֺͲ������ƼĴ���  */
    volatile uint8_t LSR;					/* ��·״̬�Ĵ���  */
    volatile uint8_t TF_CNT;				/* ���Ͷ������ݴ���  */
    volatile uint8_t STATUS;				/* ״̬�Ĵ���  */

} UART_TypeDef;
#define UART0_TxData           *(volatile unsigned char *)(UART0_BASEADDR+0x00)   //�������ݼĴ���
#define UART0_RxData           *(volatile unsigned char *)(UART0_BASEADDR+0x00)   //�������ݼĴ���
#define UART0_IER              *(volatile unsigned char *)(UART0_BASEADDR+0x01)   //�ж�ʹ�ܼĴ���
#define UART0_IIR   	       *(volatile unsigned char *)(UART0_BASEADDR+0x02)   //�ж�״̬�Ĵ�
#define UART0_FCR   	       *(volatile unsigned char *)(UART0_BASEADDR+0x02)	  //FIFO���ƼĴ���
#define UART0_LCR   	       *(volatile unsigned char *)(UART0_BASEADDR+0x03)   //��·���ƼĴ���
#define UART0_SAMPLE_CTRL      *(volatile unsigned char *)(UART0_BASEADDR+0x04)   //bit���ڻ��ֺͲ������ƼĴ���
#define UART0_LSR  	           *(volatile unsigned char *)(UART0_BASEADDR+0x05)   //��·״̬�Ĵ���
#define UART0_TF_CNT   	       *(volatile unsigned char *)(UART0_BASEADDR+0x06)   //���Ͷ������ݴ���
#define UART0_STATUS   	       *(volatile unsigned char *)(UART0_BASEADDR+0x07)   //״̬�Ĵ���

#define UART0_DL_L   	       *(volatile unsigned char *)(UART0_BASEADDR+0x00)   //��Ƶֵ���ֽڼĴ���
#define UART0_DL_H   	       *(volatile unsigned char *)(UART0_BASEADDR+0x01)   //��Ƶֵ���ֽڼĴ���
#define UART0_DL_D   	       *(volatile unsigned char *)(UART0_BASEADDR+0x02)   //��ƵֵС���Ĵ���

/*****************************UART1 REGS********************************/
#define UART1_TxData           *(volatile unsigned char *)(UART1_BASEADDR+0x00)   //�������ݼĴ���
#define UART1_RxData           *(volatile unsigned char *)(UART1_BASEADDR+0x00)   //�������ݼĴ���
#define UART1_IER              *(volatile unsigned char *)(UART1_BASEADDR+0x01)   //�ж�ʹ�ܼĴ���
#define UART1_IIR   	       *(volatile unsigned char *)(UART1_BASEADDR+0x02)   //�ж�״̬�Ĵ�
#define UART1_FCR   	       *(volatile unsigned char *)(UART1_BASEADDR+0x02)	  //FIFO���ƼĴ���
#define UART1_LCR   	       *(volatile unsigned char *)(UART1_BASEADDR+0x03)   //��·���ƼĴ���
#define UART1_SAMPLE_CTRL      *(volatile unsigned char *)(UART1_BASEADDR+0x04)   //bit���ڻ��ֺͲ������ƼĴ���
#define UART1_LSR  	           *(volatile unsigned char *)(UART1_BASEADDR+0x05)   //��·״̬�Ĵ���
#define UART1_TF_CNT   	       *(volatile unsigned char *)(UART1_BASEADDR+0x06)   //���Ͷ������ݴ���
#define UART1_STATUS   	       *(volatile unsigned char *)(UART1_BASEADDR+0x07)   //״̬�Ĵ���

#define UART1_DL_L   	       *(volatile unsigned char *)(UART1_BASEADDR+0x00)   //��Ƶֵ���ֽڼĴ���
#define UART1_DL_H   	       *(volatile unsigned char *)(UART1_BASEADDR+0x01)   //��Ƶֵ���ֽڼĴ���
#define UART1_DL_D   	       *(volatile unsigned char *)(UART1_BASEADDR+0x02)   //��ƵֵС���Ĵ���

/*****************************UART2 REGS********************************/
#define UART2_TxData           *(volatile unsigned char *)(UART2_BASEADDR+0x00)   //�������ݼĴ���
#define UART2_RxData           *(volatile unsigned char *)(UART2_BASEADDR+0x00)   //�������ݼĴ���
#define UART2_IER              *(volatile unsigned char *)(UART2_BASEADDR+0x01)   //�ж�ʹ�ܼĴ���
#define UART2_IIR   	       *(volatile unsigned char *)(UART2_BASEADDR+0x02)   //�ж�״̬�Ĵ�
#define UART2_FCR   	       *(volatile unsigned char *)(UART2_BASEADDR+0x02)	//FIFO���ƼĴ���
#define UART2_LCR   	       *(volatile unsigned char *)(UART2_BASEADDR+0x03)   //��·���ƼĴ���
#define UART2_SAMPLE_CTRL      *(volatile unsigned char *)(UART2_BASEADDR+0x04)   //bit���ڻ��ֺͲ������ƼĴ���
#define UART2_LSR  	           *(volatile unsigned char *)(UART2_BASEADDR+0x05)   //��·״̬�Ĵ���
#define UART2_TF_CNT   	       *(volatile unsigned char *)(UART2_BASEADDR+0x06)   //���Ͷ������ݴ���
#define UART2_STATUS   	       *(volatile unsigned char *)(UART2_BASEADDR+0x07)   //״̬�Ĵ���

#define UART2_DL_L       	   *(volatile unsigned char *)(UART2_BASEADDR+0x00)   //��Ƶֵ���ֽڼĴ���
#define UART2_DL_H      	   *(volatile unsigned char *)(UART2_BASEADDR+0x01)   //��Ƶֵ���ֽڼĴ���
#define UART2_DL_D      	   *(volatile unsigned char *)(UART2_BASEADDR+0x02)   //��ƵֵС���Ĵ���


#define UART0              ((UART_TypeDef *) UART0_BASEADDR)
#define UART1              ((UART_TypeDef *) UART1_BASEADDR)
#define UART2              ((UART_TypeDef *) UART2_BASEADDR)
#define UART_PRINT			    UART0
//#define UART_PRINT			    UART1
//#define UART_PRINT				UART2


/******************  EXTI REGS  ******************/
typedef struct
{
    uint32_t EXINT_EN;
    uint32_t EXINT_POL;
    uint32_t EXINT_EDGE;
    uint32_t EXINT_SRC;
} EXTI_TypeDef;
#define PMU_Exti                    (0x20)
#define EXTI_BASE             (PMU_BASE + PMU_Exti)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)

/******************  SPI REGS  ******************/

typedef struct
{
    volatile uint8_t SPCR;			/* ���ƼĴ��� */
    volatile uint8_t SPSR;			/* ״̬�Ĵ��� */
    volatile uint8_t DATA;			/* ���ݼĴ��� */
    volatile uint8_t SPER;			/* �ⲿ�Ĵ��� */
    volatile uint8_t PARAM;			/* �������ƼĴ��� */
    volatile uint8_t SOFTCS;			/* Ƭѡ���ƼĴ��� */
    volatile uint8_t TIMING;			/* ʱ����ƼĴ��� */
} SPI_TypeDef;
#define SPI                             ((SPI_TypeDef *) SPI_BASE)
#define SPI_SPCR		                 *(volatile unsigned char *)(SPI_BASE+0x00) //���ƼĴ���
#define SPI_SPSR		                 *(volatile unsigned char *)(SPI_BASE+0x01) //״̬�Ĵ���
#define SPI_TxFIFO		                 *(volatile unsigned char *)(SPI_BASE+0x02) //���ݼĴ���
#define SPI_RxFIFO		                 *(volatile unsigned char *)(SPI_BASE+0x02) //���ݼĴ���
#define SPI_SPER		                 *(volatile unsigned char *)(SPI_BASE+0x03) //�ⲿ�Ĵ���
#define SPI_SFC_PARAM	                 *(volatile unsigned char *)(SPI_BASE+0x04) //�������ƼĴ���
#define SPI_SFC_SOFTCS	                 *(volatile unsigned char *)(SPI_BASE+0x05) //Ƭѡ���ƼĴ���
#define SPI_SFC_TIMING	                 *(volatile unsigned char *)(SPI_BASE+0x06) //ʱ����ƼĴ���


/*******************************TIMER REGS*********************************/
#define TIMER_CFG  	 	       *(volatile unsigned int *)(TIMER_BASE+0x00)   //���üĴ���
#define TIMER_CNT		       *(volatile unsigned int *)(TIMER_BASE+0x04)   //����ֵ�Ĵ���
#define TIMER_CMP		       *(volatile unsigned int *)(TIMER_BASE+0x08)   //�Ƚ�ֵ�Ĵ���
#define TIMER_STP              *(volatile unsigned int *)(TIMER_BASE+0x0C)   //����ֵ�Ĵ���

/*******************************I2C REGS********************************/
#define I2C_PRERL	           *(volatile unsigned char *)(I2C_BASE+0x00)     //��Ƶֵ���ֽڼĴ���
#define I2C_PRERH 	           *(volatile unsigned char *)(I2C_BASE+0x01)     //��Ƶֵ���ֽڼĴ���
#define I2C_CTR   	           *(volatile unsigned char *)(I2C_BASE+0x02)     //���ƼĴ���
#define I2C_TXR   	           *(volatile unsigned char *)(I2C_BASE+0x03)     //���ݼĴ���
#define I2C_RXR   	           *(volatile unsigned char *)(I2C_BASE+0x03)     //���ݼĴ���
#define I2C_CR		           *(volatile unsigned char *)(I2C_BASE+0x04)     //����Ĵ���
#define I2C_SR		           *(volatile unsigned char *)(I2C_BASE+0x04)     //״̬�Ĵ���
#define I2C_BLTOP		       *(volatile unsigned char *)(I2C_BASE+0x05)     //��������ʱ��Ĵ���
#define I2C_SADDR	           *(volatile unsigned char *)(I2C_BASE+0x07)     //��ģʽ��ַ�Ĵ���

/*****************************DMA REGS**********************************/
#define DMA_SOURCE             *(volatile unsigned int *)(DMA_BASE+0x00)    //DMA����Դ��ַд�˿�
#define DMA_COUNT              *(volatile unsigned int *)(DMA_BASE+0x04)    //DMA�������ݳ��ȶ�д�˿�
#define DMA_CMD_STATUS         *(volatile unsigned int *)(DMA_BASE+0x08)    //�����״̬�Ĵ���
#define DMA_INT_STATUS         *(volatile unsigned int *)(DMA_BASE+0x0c)    //�жϺ�״̬�Ĵ���
#define DMA_SOURCE0   	       *(volatile unsigned int *)(DMA_BASE+0x10)    //���������0��Դ��ַ����
#define DMA_SOURCE1  	       *(volatile unsigned int *)(DMA_BASE+0x14)    //���������1��Դ��ַ����
#define DMA_COUNT0             *(volatile unsigned int *)(DMA_BASE+0x18)    //���������0��DMA���Ȳ���
#define DMA_COUNT1             *(volatile unsigned int *)(DMA_BASE+0x1c)    //���������1��DMA���Ȳ���

/*****************************VPWM REGS**********************************/
#define VPWM_CFG               *(volatile unsigned int *)(VPWM_BASE+0x00)   //�㷨����
#define VPWM_WPORT_STATUS      *(volatile unsigned int *)(VPWM_BASE+0x08)   //����д�˿�״̬
#define VPWM_WPORT             *(volatile unsigned int *)(VPWM_BASE+0x0c)   //����д�˿�

/*****************************TSENSOR REGS**********************************/
#define TS_CTRL                *(volatile unsigned int *)(TSENSOR_BASE+0x00)     //���ƼĴ���
#define TS_STAT                *(volatile unsigned int *)(TSENSOR_BASE+0x04)     //״̬�Ĵ���
#define TS_OSCTH       	       *(volatile unsigned int *)(TSENSOR_BASE+0x08)     //����/��ֵ�Ĵ���
#define TS_POLLTIM             *(volatile unsigned int *)(TSENSOR_BASE+0x0c)     //ɨ��ʱ��Ĵ���
#define TS_CHNATTR(a)          *(volatile unsigned int *)(TSENSOR_BASE+0x40+a*4) //ͨ�������Ĵ���x12
#define TS_CNTRES(a)           *(volatile unsigned int *)(TSENSOR_BASE+0x80+a*4) //��������Ĵ���x12

/*****************************FLASH REGS********************************/
#define GPIO_LOW    0  //GPIO��
#define GPIO_HIGH   1 //GPIO��

#define RTC_FREQ   	           *(volatile unsigned int *)(RTC_BASE+0x00)    //��Ƶֵ�Ĵ���
#define RTC_CFG   	           *(volatile unsigned int *)(RTC_BASE+0x04)    //���üĴ���
#define RTC_RTC0   	           *(volatile unsigned int *)(RTC_BASE+0x08)    //ʱ��ֵ�Ĵ���0
#define RTC_RTC1   	           *(volatile unsigned int *)(RTC_BASE+0x0c)    //ʱ��ֵ�Ĵ���1

typedef struct
{
    INT32U	c32k_trim	:4;
    INT32U	c32k_speed	:1;
    INT32U	c32k_sel	:1;
    INT32U	osc8m_en	:1;
    INT32U	c8m_sel		:1;
    INT32U	clkup_dly	:2;
    INT32U	input_hold	:1;
    INT32U	fast_ram	:1;
    INT32U	tsensor_off	:1;
    INT32U	rtc_off		:1;
    INT32U	uart2_off	:1;
    INT32U	dram_pd		:1;
    INT32U	adc_on		:1;
    INT32U	adci0_ien	:1;
    INT32U	adci_pd		:1;
    INT32U	adci_pu		:1;
    INT32U	adc_en		:4;
    INT32U	batdet_sel	:2;
    INT32U	spi_start	:1;
    INT32U	compact_mem	:1;
    INT32U	soft_flag	:4;
} PMU_ChipCtrlStruct;

#define spPMU_ChipCtrl		((volatile PMU_ChipCtrlStruct *)(PMU_BASE))
#define WriteKeyReg(LeftData,ReghtData)\
    {\
        unsigned char GlobalIntFlag = IsGlobalIntOpen();\
        DisableInt();\
        LeftData     = ReghtData;\
        if(GlobalIntFlag){\
            EnableInt();\
        }\
    }


#elif defined(LS1C103)
#define UNCACHED_MEMORY_ADDR 0x00000000
#define PHYS_TO_UNCACHED(x) ((x) | UNCACHED_MEMORY_ADDR)
#define RAM0_BASE	    0x10000000
#define RAM1_BASE           0x10001000
#define SPI_MEM_BASE        0x20000000
#define FLASH_MEM_BASE      0x18000000
#define ATIM_BASE           PHYS_TO_UNCACHED(0x00001000)
#define GTIM_BASE           PHYS_TO_UNCACHED(0x00002000)
#define BTIM_BASE           PHYS_TO_UNCACHED(0x00003000)
#define ADC_BASE            PHYS_TO_UNCACHED(0x00004000)
#define DMA_BASE            PHYS_TO_UNCACHED(0x00005000)
#define CRC_BASE            PHYS_TO_UNCACHED(0x00006000)
#define FLASH_BASE          PHYS_TO_UNCACHED(0x00007000)
#define SPI_BASE            PHYS_TO_UNCACHED(0x00008000)
#define UART0_BASEADDR      PHYS_TO_UNCACHED(0x00009000)
#define UART1_BASEADDR      PHYS_TO_UNCACHED(0x00009100)
#define I2C_BASE            PHYS_TO_UNCACHED(0x0000a000)
#define INTC_BASE           PHYS_TO_UNCACHED(0x0000b000)
#define PMU_BASE	    PHYS_TO_UNCACHED(0x0000c000)
#define RTC_BASE	    PHYS_TO_UNCACHED(0x0000c800)
#define IOCFG_BASE	    PHYS_TO_UNCACHED(0x0000d000)

#define ATE_Freq			   (*(volatile int *)0x180101b0 / 4 )

typedef struct
{
    volatile uint32_t CHIPCTRL;
    volatile uint32_t CMDSTS;
    volatile uint32_t COUNT;
    volatile uint32_t COMPARE;
    volatile uint32_t RST_CTRL;
    volatile uint32_t CLK_CTRL;
    volatile uint32_t SR_PROT;
    volatile uint32_t RESERVED0;
    volatile uint32_t RESERVED1;
    volatile uint32_t RESERVED2;
    volatile uint32_t RESERVED3;
    volatile uint32_t RESERVED4;
    volatile uint32_t WDT_CFG;
    volatile uint32_t WDT_FEED;
    volatile uint32_t POWER_CFG;
    volatile uint32_t CMDW;
    volatile uint32_t RESERVED5;
    volatile uint32_t RESERVED6;
    volatile uint32_t RESERVED7;
    volatile uint32_t RESERVED8;
    volatile uint32_t RESERVED9;
    volatile uint32_t RESERVED10;
    volatile uint32_t RESERVED11;
    volatile uint32_t RESERVED12;
    volatile uint32_t USER_DAT0;
    volatile uint32_t USER_DAT1;
    volatile uint32_t USER_DAT2;
    volatile uint32_t USER_DAT3;
} PMU_TypeDef;
#define PMU_ChipCtrl               0x00
#define PMU_Command                0x04
#define PMU_Count                  0x08
#define PMU_Compare                0x0c
#define PMU_WdtCfg                 0x30
#define PMU_WdtFeed                0x34
#define PMU_PowerCfg               0x38
#define PMU_CommandW               0x3c
#define PMU_GPIOAOE_OFFSET         0x40
#define PMU_GPIOAO_OFFSET          0x44
#define PMU_GPIOAI_OFFSET          0x48
#define PMU_GPIOBOE_OFFSET         0x50
#define PMU_GPIOBO_OFFSET          0x54
#define PMU_GPIOBI_OFFSET          0x58
#define PMU_PULSE0_OFFSET          0x60
#define PMU_PULSE1_OFFSET          0x64
#define PMU_ADCCTRL_OFFSET         0x6c
#define PMU_ADCDAT_OFFSET          0x70
//PMU access by 8-bit
#define PMU_GPIOBIT_OFFSET         0x80
#define PMU_SoftRst		    0x10
#define PMU_ClkOff		    0x14
#define PMU_SrProt		    0x18
#define PMU_UserDat1		    0x64
#define PMU_UserDat2		    0x68
#define PMU_UserDat3		    0x6c
#define PMU_UserDat0		    0x60
#define PMU_CHIPCTRL  	  *(volatile unsigned int*)(PMU_BASE+PMU_ChipCtrl)
#define PMU_CMDSTS        *(unsigned volatile int*)(PMU_BASE+PMU_Command)
#define PMU_COUNT         *(unsigned volatile int*)(PMU_BASE+PMU_Count)
#define PMU_COMPARE       *(unsigned volatile int*)(PMU_BASE+PMU_Compare)
//pmu
#define PMU_SOFTRST       *(unsigned volatile int*)(PMU_BASE+PMU_SoftRst)
#define PMU_SRPROT        *(volatile unsigned char *)(PMU_BASE+PMU_SrProt)
#define PMU_CLKOFF        *(unsigned volatile int*)(PMU_BASE+PMU_ClkOff)
#define PMU_WDTCFG        *(unsigned volatile int*)(PMU_BASE+PMU_WdtCfg)
#define PMU_WDTFEED       *(unsigned volatile int*)(PMU_BASE+PMU_WdtFeed)
#define PMU_CMDW       	  *(unsigned volatile int*)(PMU_BASE+PMU_CommandW)

#define SRPROT	PMU_SRPROT
#define PMU					((PMU_TypeDef *) PMU_BASE)

typedef struct
{
    volatile uint32_t INTC_EN;					/* �ж�ʹ�ܼĴ��� */
    volatile uint32_t RESERVED0;
    volatile uint32_t INTC_OUT;
} INT_TypeDef;
#define INT_EN  *(volatile unsigned char*)(INTC_BASE + 0x0)
#define INT_OUT *(volatile unsigned char*)(INTC_BASE + 0x8)
#define INT					((INT_TypeDef *) INTC_BASE)


typedef struct
{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_TypeDef;

typedef struct
{
    volatile uint32_t IOSEL;
} AFIO_TypeDef;


#define AFIO_REG_BASE       (IOCFG_BASE + 0x00000000)
#define EXTI_REG_BASE       (IOCFG_BASE + 0x00000100)
#define GPIOA_REG_BASE      (IOCFG_BASE + 0x00000200)
#define GPIOB_REG_BASE      (IOCFG_BASE + 0x00000300)

#define AFIO_Sela      0x00
#define AFIO_Selb      0x04

#define AFIO_PORTA      *(unsigned volatile int*)(AFIO_REG_BASE+AFIO_Sela)
#define AFIO_PORTB      *(unsigned volatile int*)(AFIO_REG_BASE+AFIO_Selb)


#define EXTI_En            0x00
#define EXTI_Pol           0x04
#define EXTI_Edge          0x08
#define EXTI_Src           0x0c

#define EXTI_EN      *(unsigned volatile int*)(EXTI_REG_BASE+EXTI_En  )
#define EXTI_POL     *(unsigned volatile int*)(EXTI_REG_BASE+EXTI_Pol )
#define EXTI_EDGE    *(unsigned volatile int*)(EXTI_REG_BASE+EXTI_Edge)
#define EXTI_SRC     *(unsigned volatile int*)(EXTI_REG_BASE+EXTI_Src )


#define GPIO_CRL              0x00
#define GPIO_CRH              0x04
#define GPIOA_BASE            (GPIOA_REG_BASE)
#define GPIOB_BASE            (GPIOB_REG_BASE)

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)



#define AFIOBASE	(IOCFG_BASE)
#define AFIOA_BASE	(AFIOBASE + AFIO_Sela)
#define AFIOB_BASE	(AFIOBASE + AFIO_Selb)




#define AFIOA		((AFIO_TypeDef *) AFIOA_BASE)
#define AFIOB		((AFIO_TypeDef *) AFIOB_BASE)


typedef struct
{
    volatile uint32_t DAT_DL_L ;			/* �������ݼĴ��� �� ��Ƶֵ���ֽڼĴ��� */
    volatile uint32_t IER_DL_H;			/* �ж�ʹ�ܼĴ��� �� ��Ƶֵ���ֽڼĴ��� */
    volatile uint32_t IIR_FCR_DL_D;		/* �ж�״̬�Ĵ棨ֻ���� FIFO���ƼĴ��� ��ֻд��  ��   ��ƵֵС���Ĵ���  */
    volatile uint32_t LCR;			/* ��·���ƼĴ���  */
    volatile uint32_t MCR;			/* MODEM���ƼĴ���  */
    volatile uint32_t LSR;			/* ��·״̬�Ĵ���  */

} UART_TypeDef;

#define UART0_TxData                  *(unsigned volatile int*)(UART0_BASEADDR+0x0)
#define UART0_RxData                  *(unsigned volatile int*)(UART0_BASEADDR+0x0)
#define UART0_IER                     *(unsigned volatile int*)(UART0_BASEADDR+0x4)
#define UART0_IIR                     *(unsigned volatile int*)(UART0_BASEADDR+0x8)
#define UART0_FCR                     *(unsigned volatile int*)(UART0_BASEADDR+0x8)
#define UART0_LCR                     *(unsigned volatile int*)(UART0_BASEADDR+0xc)
#define UART0_MCR                     *(unsigned volatile int*)(UART0_BASEADDR+0x10)
#define UART0_LSR                     *(unsigned volatile int*)(UART0_BASEADDR+0x14)
#define UART0_DLL                     *(unsigned volatile int*)(UART0_BASEADDR+0x0)
#define UART0_DLH                     *(unsigned volatile int*)(UART0_BASEADDR+0x4)
#define UART0_DLD                     *(unsigned volatile int*)(UART0_BASEADDR+0x8)

#define UART1_TxData                  *(unsigned volatile int*)(UART1_BASEADDR+0x0)
#define UART1_RxData                  *(unsigned volatile int*)(UART1_BASEADDR+0x0)
#define UART1_IER                     *(unsigned volatile int*)(UART1_BASEADDR+0x4)
#define UART1_IIR                     *(unsigned volatile int*)(UART1_BASEADDR+0x8)
#define UART1_FCR                     *(unsigned volatile int*)(UART1_BASEADDR+0x8)
#define UART1_LCR                     *(unsigned volatile int*)(UART1_BASEADDR+0xc)
#define UART1_MCR                     *(unsigned volatile int*)(UART1_BASEADDR+0x10)
#define UART1_LSR                     *(unsigned volatile int*)(UART1_BASEADDR+0x14)
#define UART1_DLL                     *(unsigned volatile int*)(UART1_BASEADDR+0x0)
#define UART1_DLH                     *(unsigned volatile int*)(UART1_BASEADDR+0x4)
#define UART1_DLD                     *(unsigned volatile int*)(UART1_BASEADDR+0x8)


#define UART0                  ((UART_TypeDef *) UART0_BASEADDR)
#define UART1                  ((UART_TypeDef *) UART1_BASEADDR)
#define UART_PRINT				UART0

#define RTC_FREQ   	           *(volatile unsigned int *)(RTC_BASE+0x00)    //��Ƶֵ�Ĵ���
#define RTC_CFG   	           *(volatile unsigned int *)(RTC_BASE+0x04)    //���üĴ���
#define RTC_RTC0   	           *(volatile unsigned int *)(RTC_BASE+0x08)    //ʱ��ֵ�Ĵ���0
#define RTC_RTC1   	           *(volatile unsigned int *)(RTC_BASE+0x0c)    //ʱ��ֵ�Ĵ���1

/******************  EXTI REGS  ******************/
typedef struct
{
    uint32_t EXINT_EN;
    uint32_t EXINT_POL;
    uint32_t EXINT_EDGE;
    uint32_t EXINT_SRC;
} EXTI_TypeDef;
#define EXTI_BASE             (EXTI_REG_BASE)
#define EXTI                  ((EXTI_TypeDef *) EXTI_BASE)

/******************  SPI REGS  ******************/

typedef struct
{
    volatile uint32_t SPCR;			/* ���ƼĴ��� */
    volatile uint32_t SPSR;			/* ״̬�Ĵ��� */
    volatile uint32_t DATA;			/* ���ݼĴ��� */
    volatile uint32_t SPER;			/* �ⲿ�Ĵ��� */
    volatile uint32_t PARAM;			/* �������ƼĴ��� */
    volatile uint32_t SOFTCS;			/* Ƭѡ���ƼĴ��� */
    volatile uint32_t TIMING;			/* ʱ����ƼĴ��� */
} SPI_TypeDef;
#define SPI_SPCR                      *(unsigned volatile int*)(SPI_BASE+0x0)
#define SPI_SPSR                      *(unsigned volatile int*)(SPI_BASE+0x4)
#define SPI_DATA                      *(unsigned volatile int*)(SPI_BASE+0x8)
#define SPI_SPER                      *(unsigned volatile int*)(SPI_BASE+0xc)
#define SPI_PARAM                     *(unsigned volatile int*)(SPI_BASE+0x10)
#define SPI_SOFTCS                    *(unsigned volatile int*)(SPI_BASE+0x14)
#define SPI_TIMING                    *(unsigned volatile int*)(SPI_BASE+0x18)
#define SPI                           ((SPI_TypeDef *) SPI_BASE)


/******************  INTC REGS  ******************/
#define INTC_En      0x0
#define INTC_Clr     0x4
#define INTC_Out     0x8

#define PMU_COMMAND_Int_Wake      0x01
#define PMU_COMMAND_Int_BatFail   0x02
#define PMU_COMMAND_Int_C32kFail  0x04
#define PMU_COMMAND_Int_C8mFail   0x08
#define PMU_COMMAND_Int_RTC       0x10
#define PMU_COMMAND_Int_ExInt    0x100
#define PMU_COMMAND_Int_ALL      0x1ff

#define GPIO_OUTPUT 0x2
#define GPIO_INPUT  0x0
#define GPIO_HIGH   0x1
#define GPIO_LOW    0x0

#endif
/******************  FLASH REGS  ******************/
typedef struct
{
    volatile uint32_t CMD;				/* ����Ĵ��� */
    volatile uint32_t CAH;				/* ���ܵ�ַ�Ͻ�Ĵ��� */
    volatile uint32_t CAL;				/* ���ܵ�ַ�½�Ĵ��� */
    volatile uint32_t RESERVED0;			/* �����ֽ�  */
    volatile uint32_t VRF;				/* ����У��Ĵ��� */
    volatile uint32_t STS;				/* ״̬�Ĵ��� */
    volatile uint32_t PET;				/* ��дʱ��Ĵ��� */
} FLASH_TypeDef;

#define FLASH                   ((FLASH_TypeDef *) FLASH_BASE)
#define FLASH_CMD_REG	       *(volatile unsigned int *)(FLASH_BASE+0x00)   //����Ĵ���
#define FLASH_CAH_REG	       *(volatile unsigned int *)(FLASH_BASE+0x04)   //���ܵ�ַ�Ͻ�Ĵ���
#define FLASH_CAL_REG	       *(volatile unsigned int *)(FLASH_BASE+0x08)   //���ܵ�ַ�½�Ĵ���
#define FLASH_VRF_REG	       *(volatile unsigned int *)(FLASH_BASE+0x10)   //����Ч��Ĵ���
#define FLASH_STS_REG	       *(volatile unsigned int *)(FLASH_BASE+0x14)   //״̬�Ĵ���
#define FLASH_PET_REG	       *(volatile unsigned int *)(FLASH_BASE+0x18)   //��дʱ��Ĵ���
#ifdef  DEBUG
/*******************************************************************************
* Macro Name     : assert_param
* Description    : The assert_param macro is used for function's parameters check.
*                  It is used only if the library is compiled in DEBUG mode.
* Input          : - expr: If expr is false, it calls assert_failed function
*                    which reports the name of the source file and the source
*                    line number of the call that failed.
*                    If expr is true, it returns no value.
* Return         : None
*******************************************************************************/
#define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t* file, uint32_t line);
#else
#define assert_param(expr) ((void)0)
#endif /* DEBUG */

#endif /*_LS1X_H_ */

