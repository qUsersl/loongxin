#include "ls1x_uart.h"
#include "ls1x_gpio.h"
#include "ls1x_printf.h"

extern uint32_t g_SystemFreq;

void UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct)
{
    //uint8_t data = 0;
    unsigned char  win_size, sample_point;
    uint32_t div = 0;
    uint32_t dec = 0;
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_WORD_LENGTH(UART_InitStruct->UART_WordLength));
    assert_param(IS_UART_STOPBITS(UART_InitStruct->UART_StopBits));
    assert_param(IS_UART_PARITY(UART_InitStruct->UART_Parity));
    assert_param(IS_UART_CLOCK(UART_InitStruct->Clock_Freq));
    assert_param(IS_UART_FIFO_TRIGGER(UART_InitStruct->UART_Triger));


    win_size     = UARTx->SAMPLE_CTRL & 0x0F;
    sample_point = UARTx->SAMPLE_CTRL >> 4;
    if ((win_size == 0) || (sample_point == 0))
    {
        UARTx->SAMPLE_CTRL = 0x38;
        win_size = 8;
    }
    if(UARTx==UART2)
    {
         UARTx->SAMPLE_CTRL = 0x23;
         win_size=3;
    }

    /* ��λLCR�Ĵ���  */
    UARTx->LCR = 0x03;

    //div = (UART_InitStruct->Clock_Freq << 4);
    //div =  div / (UART_InitStruct->UART_BaudRate);      //[23:16] DL_H  [15: 8] DL_L  [ 7: 0] DL_D

     if(UARTx==UART0||UARTx==UART1)
     {
         div=UART_InitStruct->Clock_Freq/UART_InitStruct->UART_BaudRate/win_size;
         dec=UART_InitStruct->Clock_Freq - (div * UART_InitStruct->UART_BaudRate * win_size);
     }
     else
     {
         div = 32768 / UART_InitStruct->UART_BaudRate / win_size;
         dec =32768 - (div * UART_InitStruct->UART_BaudRate * win_size);//32768-28800=3968
     }
      dec = (dec * 255) / UART_InitStruct->UART_BaudRate / win_size;
    SET_BIT(UARTx->LCR,UART_Lab_En);

    //UARTx->IIR_FCR_DL_D = div & 0xff;
    //div >>= 8;
    UARTx->DAT_DL_L = div & 0xff;//���������8Mʱ�ӣ���������Ϊ0x08,������ԭ�����õľ���32kʱ�Ӳ���������Ϊ9600����ֵҲ����0x01
    div >>= 8;//����8
    UARTx->IER_DL_H = div & 0xff;//32kʱ������ֵΪ0

    UARTx->IIR_FCR_DL_D=dec & 0xFF;//32kʱ��35
    //תΪ2����Ϊ 100011=0x23

    CLEAR_BIT(UARTx->LCR,UART_Lab_En);

    UARTx->IER_DL_H = 0x00;

     //UARTx->IIR_FCR_DL_D = UART_InitStruct->UART_Triger |  UART_FIFO_TX_RST | UART_FIFO_RX_RST;

    SET_BIT(UARTx->LCR,UART_InitStruct->UART_WordLength);

    SET_BIT(UARTx->LCR,UART_InitStruct->UART_Parity);

    SET_BIT(UARTx->LCR,UART_InitStruct->UART_Parity_Bid_Control);

    SET_BIT(UARTx->LCR,UART_InitStruct->UART_StopBits);

    SET_BIT(UARTx->LCR,UART_InitStruct->UART_Break_Control);

    SET_BIT(UARTx->LCR,UART_InitStruct->UART_Parity_Control);

    UARTx->DAT_DL_L;
}

void Uart_init(UART_TypeDef* UARTx)
{

    // uint8_t data = 0;
    //  uint32_t div = 0;
    assert_param(IS_UART_PERIPH(UARTx));

    /* ��λLCR�Ĵ���  */
    UARTx->LCR = 0x03;

    SET_BIT(UARTx->LCR,UART_Lab_En);

    //UARTx->IIR_FCR_DL_D = 0x57;
    UARTx->IIR_FCR_DL_D = 0xca;
    //UARTx->DAT_DL_L = 0x4;
    UARTx->DAT_DL_L = 0x5;
    UARTx->IER_DL_H = 0x0;

    CLEAR_BIT(UARTx->LCR,UART_Lab_En);

    UARTx->IER_DL_H = 0x00;

    UARTx->IIR_FCR_DL_D =UART_FIFO_TRIGGER_1| UART_FIFO_TX_RST | UART_FIFO_RX_RST;

    UARTx->DAT_DL_L;
}

///**
//  * @brief  Fills each USART_InitStruct member with its default value.
//  * @param  USART_InitStruct: pointer to a USART_InitTypeDef structure
//  *         which will be initialized.
//  * @retval None
//  * remark:
//  * 		uart1 clock freq is 32k;
//  */
void UART_StructInit(UART_InitTypeDef* UART_InitStruct)
{
    /* USART_InitStruct members default value */
    UART_InitStruct->UART_BaudRate = 115200;
    UART_InitStruct->Clock_Freq = 8000000;
    UART_InitStruct->UART_WordLength = UART_Word_Length_8b;
    UART_InitStruct->UART_StopBits = UART_StopBits_1;
    UART_InitStruct->UART_Parity = UART_Parity_Odd ;
    UART_InitStruct->UART_Parity_Control = UART_Parity_No;
    UART_InitStruct->UART_Break_Control = UART_Break_Control_NEn;
    UART_InitStruct->UART_Parity_Bid_Control = UART_Parity_No_Bid;
    UART_InitStruct->UART_Triger = UART_FIFO_TRIGGER_1;

}
/**
 * brief��  Enables or disables the specified USART interrupts.
 * param��  USARTx: Select the USART or the UART peripheral.
 *   				 This parameter can be one of the following values:
 *   				    USART0, USART1
 * param��  USART_IT: specifies the UART interrupt sources to be enabled or disabled.
 *   	    		  This parameter can be one of the following values:
 *      				UART_IT_IME:  ������ Modem�ж�ʹ��
 *       				UART_IT_ILE:  ��·״̬�ж�ʹ��
 *      				UART_IT_ITE:  ����״̬�ж�ʹ��
 *       				UART_IT_IRE:  ����״̬�ж�ʹ��
 * param��  NewState: new state of the specified USARTx interrupts.
 *   				  This parameter can be: ENABLE or DISABLE.
 * retval�� None
 */
void UART_ITConfig(UART_TypeDef* UARTx, uint8_t UART_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_CONFIG_IT(USART_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    (NewState != DISABLE)? (SET_BIT(UARTx->IER_DL_H,UART_IT)) : (CLEAR_BIT(UARTx->IER_DL_H,UART_IT));
}

///**
// * brief�� Enables or disables the specified UART interrupts.
// * @param  USARTx: Select the USART or the UART peripheral.
// *   This parameter can be one of the following values:
// *   USART0, USART1
// * @param  NewState: new state of the specified USARTx interrupt.
// *   This parameter can be: ENABLE or DISABLE.
// * @retval None
// */
//void UART_ITCmd(UART_TypeDef* UARTx, FunctionalState NewState)
//{
//	uint8_t uartdata = 0x00;
//
//	assert_param(IS_UART_PERIPH(USARTx));
//	assert_param(IS_FUNCTIONAL_STATE(NewState));
//
//	/* clear data reg*/
//	uartdata = UARTx->DAT_DL_L;
//
//	if(UARTx != UART1)
//	{
//		/* ����uart0�ж�Ϊ �ߵ�ƽ���� */
////		INT->INT_POL |= 0x08;
//		(NewState != DISABLE)? (INT->INT_EN  |= ((uint8_t)0x08)) : (INT->INT_EN  &= ((uint8_t)0xF7));
//	}
//	else
//	{
//		/* ����uart1�ж�Ϊ �ߵ�ƽ���� */
////		INT->INT_POL |= 0x04;
//		(NewState != DISABLE)? (INT->INT_EN  |= ((uint8_t)0x04)) : (INT->INT_EN  &= ((uint8_t)0xFB));
//	}
//
//}



/**
 * brief:  Transmits single data through the USARTx peripheral.
 * param:  USARTx: Select the USART or the UART peripheral.
 *   	   This parameter can be one of the following values:
 *   	   USART0, USART1
 * param:  Data: the data to transmit.
 * retval: None
 */
void UART_SendData(UART_TypeDef* UARTx, uint8_t Data)
{
    assert_param(IS_UART_PERIPH(USARTx));

    while (!READ_BIT(UARTx->LSR,UART_LSR_FLAG_TFE));
    UARTx->DAT_DL_L = Data;
}

/**
 * brief:  Receive single data through the USARTx peripheral.
 * param:  USARTx: Select the USART or the UART peripheral.
 *   	   This parameter can be one of the following values:
 *   	   USART0, USART1
 * param:
 * retval:  the data receive.
 */
uint8_t UART_ReceiveData(UART_TypeDef* UARTx)
{
    uint8_t data = 0;
    assert_param(IS_UART_PERIPH(USARTx));
    while (!READ_BIT(UARTx->LSR,UART_LSR_FLAG_RXNE));
    data = UARTx->DAT_DL_L ;
    return data;
}

/**
  * @brief  Checks whether the specified USART flag is set or not.
  * @param  USARTx: Select the USART or the UART peripheral.
  *   This parameter can be one of the following values:
  *   USART1, USART2, USART3, UART4 or UART5.
  * @param  USART_FLAG: specifies the flag to check.
  *   This parameter can be one of the following values:
  *     	 UART_LSR_FLAG_ERR:  Error flag
  *     	 UART_LSR_FLAG_TE:   Transmit data register empty flag
  *     	 UART_LSR_FLAG_TFE:  Transmit fifo register empty flag
  *    		 UART_LSR_FLAG_BI:   break flag
  *     	 UART_LSR_FLAG_FE:   Framing Error flag
  *     	 UART_LSR_FLAG_PE:   Parity Error flag
  *     	 UART_LSR_FLAG_OE:   OverRun Error flag
  *     	 UART_LSR_FLAG_RXNE:   Receive data register not empty flag
  * @retval The new state of USART_FLAG (SET or RESET).
  */

FlagStatus UART_GetFlagStatus(UART_TypeDef* UARTx, uint8_t UART_FLAG)
{
    FlagStatus bitstatus = RESET;
    assert_param(IS_UART_PERIPH(USARTx));
    assert_param(IS_UART_LSR_FLAGS(UART_FLAG));

    if(UARTx->LSR & (UART_FLAG != (uint8_t)RESET))
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
 *@˵���� Checks whether the specified UART interrupt has occurred or not.
 *param��  USARTx: Select the USART or the UART peripheral.
 *				 This parameter can be one of the following values:
 *				 USART0�� USART1
 *
 *param  USART_IT: specifies the USART interrupt source to check.
 *				   This parameter can be one of the following values:
 *				   UART_IT_RXOT�� ���ճ�ʱ����������Ч�Һ���4���ַ�ʱ�����޲���
 *				   UART_IT_IL��	 ��ż �� ��� �� ֡���� �����ж�
 *				   UART_IT_RXNE�����ռĴ����ǿ��ж�
 *				   UART_IT_TXE��  ����fifo���ж�
 *				   UART_IT_MDM�� ������ Modem�Ĵ��������ߴ���ʵ���޴��ж�Դ
 *				   UART_IT_INTPn �Ƿ����δ������ж�
 *retval: None
 *
 *		�����ж�λ���ص������Բ�ѯʱ��һ��ֻ�����ѯһ���жϱ�־��������ͬʱ������жϱ�־ȡλ���ȥ��ѯ��
 */
ITStatus UART_GetITStatus(UART_TypeDef* UARTx, uint8_t UART_IT_FLAG)
{
    FlagStatus bitstatus = RESET;
    assert_param(IS_UART_PERIPH(USARTx));

    if(UARTx->IIR_FCR_DL_D ^ (UART_IT_FLAG == (uint8_t)RESET))
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    return bitstatus;
}
///**
// *@brief  Clears the USARTx's interrupt pending bits.
// *param��  USARTx: Select the USART or the UART peripheral.
// *		 		 USART0, USART1
// *
// *retval None
// */
//
//void UART_ClearIT(UART_TypeDef* UARTx)
//{
//	//uint8_t uartdata = 0x00;
//
//	assert_param(IS_UART_PERIPH(USARTx));
//	assert_param(IS_FUNCTIONAL_STATE(NewState));
//
//	/* clear data reg*/
//	//uartdata = UARTx->DAT_DL_L;
//
//	if(UARTx != UART1)
//	{
//		INT->INT_CLR |= 0x08;
//	}
//	else
//	{
//		INT->INT_CLR |= 0x04;
//
//	}
//
//}

/**
 *@˵���� Clears the USARTx's interrupt pending bits.
 *param��  USARTx: Select the USART or the UART peripheral.
 *				 This parameter can be one of the following values:
 *				 USART0�� USART1
 *
 *param  USART_IT: specifies the USART interrupt source to check.
 *				   This parameter can be one of the following values:
 *				   UART_IT_RXOT�� ���ճ�ʱ����������Ч�Һ���4���ַ�ʱ�����޲���
 *				   UART_IT_IL��	 ��ż �� ��� �� ֡���� �����ж�
 *				   UART_IT_RXNE�����ռĴ����ǿ��ж�
 *				   UART_IT_TXE��  ����fifo���ж�
 *				   UART_IT_MDM�� ������ Modem�Ĵ��������ߴ���ʵ���޴��ж�Դ
 *retval None
 *remark��
 *			 UART_IT_RXOT�� 	�����ݼĴ������ɸ�λ�жϱ�־λ
 *			 UART_IT_IL��       	��LSR�Ĵ������ɸ�λ�жϱ�־λ
 *			 UART_IT_RXNE: 	�����ݼĴ������ɸ�λ�жϱ�־λ
 *			 UART_IT_TXE:  	д���ݼĴ�������жϼĴ������ɸ�λ�жϱ�־λ
 *			 UART_IT_MDM:  	��Modem�Ĵ������ɸ�λ�жϱ�־λ
 *			 һ�㲻�ÿ���������������������жϱ�־λ���Զ��������Ӱ���´���Ӧ����������ú��������Ӧ�жϼĴ�����
 */
uint8_t UART_ClearITPendingBit(UART_TypeDef* UARTx, uint16_t UART_IT)
{
    uint8_t data = 0;
    assert_param(IS_UART_PERIPH(USARTx));
    assert_param(IS_UART_GET_IT(UART_IT_FLAG));
    switch(UART_IT)
    {
        case UART_IT_RXOT:
            data = UARTx->DAT_DL_L;
            break;
        case UART_IT_IL:
            data = UARTx->LSR;
            break;
        case UART_IT_RXNE:
            data = UARTx->DAT_DL_L;
            break;
        case UART_IT_TXE:
            data = UARTx->IIR_FCR_DL_D;
            break;
//	case UART_IT_MDM:
//		data = UARTx->MSR;
//		break;
        default:
            break;
    }
    return data;

}

uint8_t x_getchar(void)
{
    uint8_t chr;
    chr = UART0_RxData ;
    return chr;
}

void UartInit(void)
{
    UART_InitTypeDef UART_InitStruct;
    UART_StructInit(&UART_InitStruct);

    UART_InitStruct.Clock_Freq = g_SystemFreq;
    UART_InitStruct.UART_BaudRate = 115200;
    UART_Init(UART1,&UART_InitStruct);
    UART_ITConfig(UART1,UART_IT_IRE,DISABLE);

}

void Uart0_init(uint32_t baud)
{
    gpio_pin_remap(GPIO_PIN_6,GPIO_FUNC_MAIN);          //�ܽŸ���ΪRX
    gpio_pin_remap(GPIO_PIN_7,GPIO_FUNC_MAIN);          //�ܽŸ���ΪTX
    UART_InitTypeDef UART_InitStruct;
    UART_StructInit(&UART_InitStruct);

    UART_InitStruct.Clock_Freq = g_SystemFreq;
    UART_InitStruct.UART_BaudRate = baud;
    UART_Init(UART0,&UART_InitStruct);

    INT_POL |= 0x08;
    INT_EN |= 0x08;
    UART_ITConfig(UART0,UART_IT_IRE,ENABLE);

}

void Uart1_init(uint32_t baud)
{
    gpio_pin_remap(GPIO_PIN_8,GPIO_FUNC_MAIN);          //�ܽŸ���ΪRX
    gpio_pin_remap(GPIO_PIN_9,GPIO_FUNC_MAIN);          //�ܽŸ���ΪTX

    UART_InitTypeDef UART_InitStruct;
    UART_StructInit(&UART_InitStruct);

    UART_InitStruct.Clock_Freq = g_SystemFreq;
    UART_InitStruct.UART_BaudRate = baud;
    UART_Init(UART1,&UART_InitStruct);

//        INT_POL |= 0x04;
//        INT_EN |= 0x04;

    UART_ITConfig(UART1,UART_IT_IRE,!ENABLE);

}


void Uart2_init(uint32_t baud)
{
    gpio_pin_remap(GPIO_PIN_38,2);          //�ܽŸ���ΪRX
    gpio_pin_remap(GPIO_PIN_39,2);
    UART_InitTypeDef UART_InitStruct;
    UART_StructInit(&UART_InitStruct);
    UART_InitStruct.Clock_Freq = 32768;
    UART_InitStruct.UART_BaudRate =  baud;
    UART_Init(UART2,&UART_InitStruct);
    UART_ITConfig(UART2,UART_IT_IRE,!ENABLE);

}



void Uart1_init_test(uint32_t f,uint32_t baud)
{
    gpio_pin_remap(GPIO_PIN_8,GPIO_FUNC_MAIN);          //�ܽŸ���ΪRX
    gpio_pin_remap(GPIO_PIN_9,GPIO_FUNC_MAIN);          //�ܽŸ���ΪTX

    UART_InitTypeDef UART_InitStruct;
    UART_StructInit(&UART_InitStruct);

    UART_InitStruct.Clock_Freq = f;
    UART_InitStruct.UART_BaudRate = baud;
    UART_Init(UART1,&UART_InitStruct);
    UART_ITConfig(UART1,UART_IT_IRE,DISABLE);
}

void Uart0_send(unsigned char chr)
{
    UART_SendData(UART0, chr);
}
void Uart1_send(unsigned char chr)
{
    UART_SendData(UART1, chr);
}
void Uart2_send(unsigned char chr)
{
    UART_SendData(UART2, chr);
}

