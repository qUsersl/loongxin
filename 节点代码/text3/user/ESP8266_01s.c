/*
 * ESP8266_01s.c
 *
 * created: 2025/4/9
 *  author: 
 */
 
#include "ESP8266_01s.h"
#include "ls1x_string.h"
#include "ls1x_latimer.h"
#include "config.h"

extern void printf_Data();


void ESP8266_Init()
{
    printf("\n");    //客户端
    printf("AT\n");
    delay_ms(50);
    printf("AT+CWMODE=1\n");
    delay_ms(50);
    printf("AT+RST\n");
    delay_s(2);
    printf("AT+CIPMUX=0\n");
    delay_ms(50);
    printf("AT+CWJAP=\"esp8266\",\"wenjie01\"\n");
    delay_s(5);
    printf("AT+CIPSTART=\"TCP\",\"192.168.4.1\",8080\n");
    delay_ms(50);
    
    //printf("\n");   //服务端
    //printf("AT\n");
    //delay_ms(50);
    //printf("AT+CWMODE=2\n");
    //delay_ms(50);
    //printf("AT+RST\n");
    //delay_s(1);
    //delay_s(1);
    //printf("AT+CWSAP=\"esp8266\",\"wenjie01\",5,3\n");
    //delay_ms(500);
    //printf("AT+CIPMUX=1\n");
    //delay_ms(50);
    //printf("AT+CIPSERVER=1,8080\n");
    //delay_ms(50);
}

void ESP_SendData()
{
    printf("AT+CIPSEND=19\r\n");
    delay_s(1);
}

