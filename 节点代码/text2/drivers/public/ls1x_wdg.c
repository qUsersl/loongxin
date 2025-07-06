#include "ls1x_wdg.h"
#include "Config.h"
#include "ls1x.h"

static uint16_t WDG_getOddValue(uint32_t second)
{
    int i = 0;
    int calc = 0;

    //second &= 0xffff7fff; // max 15bit
    for (i = 0; i < 15; i++)
    {
        if (second & (0x1 << i))
        {
            calc++;
        }
    }
    return ((calc % 2 == 0) ? 0x8000 : 0x0000);
}

/// @brief ���ÿ��Ź�ʱ�䣨s��
/// @param second������ʱ�䣬 Ҫ��<0x7fff��Ҫ������У��
/// @details: second ���λ(��15λ)Ϊ��żУ��λ��Ϊ��У��λ��
void WDG_SetWatchDog(uint32_t second)
{
    second = (second &0x7fff); // max 15bit
    second |= WDG_getOddValue(second);

    PMU->WDT_FEED = 0xa55a55aa;
    second = (((~second)<<16) | second);
    //printf("second: %08x \r\n", second);
    PMU->WDT_CFG = second;
}

void WDG_DogFeed(void)
{
    PMU->WDT_FEED = 0xa55a55aa;
}


void WdgInit(void)
{
    WDG_SetWatchDog(0x80007fff);
}

