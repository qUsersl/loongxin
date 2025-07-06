#include "test.h"
#include "ls1x.h"
#include "ls1x_latimer.h"

uint32_t get_count(void)
{
    // ��ȡ�������е�ֵ
    uint32_t tem_count = 0;
    asm volatile("rdtimel.w	%0, $r0":"=r" (tem_count));
    return tem_count;
}

void open_count()
{
    asm ("li.w $r12, 0x10; csrxchg $r0, $r12, 0xaf;":::"$r12");
}
void close_count()
{
    asm ("li.w $r12, 0x10; csrxchg $r12, $r12, 0xaf;":::"$r12");
}

void start_count(TIMER_COUNT *timer_count)
{
    timer_count->begin = 0;
    timer_count->end = 0;
    //��������ʼֵ�ŵ�start��
    timer_count->begin = get_count();
}

uint32_t stop_count(TIMER_COUNT *timer_count)
{
    //������������ֵ�ŵ�end��
    timer_count->end = get_count();
    if(timer_count->end >= timer_count->begin)
    {
        return (timer_count->end - timer_count->begin);
    }
    else
    {
        uint32_t end = -1;
        return (end - timer_count->begin + timer_count->end);
    }
}

void delay_cycle(uint32_t num)
{
    uint32_t count = 0;
    TIMER_COUNT timer_count = {0, 0};

//    open_count();
    start_count(&timer_count);

    while (count < num)
    {
        count = stop_count(&timer_count);
    }
//    close_count();
}

void delay_us(uint32_t x)	    //us��λ
{
    delay_cycle(x * 8);
}

void delay_ms(uint32_t x)  	//ms��λ
{
    delay_cycle(x * 8000);
}

void delay_s(uint32_t x)  	//s��λ
{
    delay_ms(x * 1000); //8*1000*1000
}

void SetTime(tsTimeType *TimeType, uint32_t TimeInter)
{

    TimeType->TimeStart = get_count();//��ȡ��ʼʱ��
    TimeType->TimeInter = 8 * 1000 * TimeInter; //���ʱ��
}

uint8_t CompareTime(tsTimeType *TimeType)
{

    return ((get_count() - TimeType->TimeStart) >= TimeType->TimeInter); //ʱ�䵽��

}

