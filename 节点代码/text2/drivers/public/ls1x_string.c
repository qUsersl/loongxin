#include "ls1x_string.h"
#include "ls1x_printf.h"
/***********************************************************************
function:	�Ƚ�cs��ct���ֽ�
@param	:	cs		Ҫ�Ƚϵ�����
			ct  	Ҫ�Ƚϵ�����
			count	����
@other	:    �ú����ǰ��ֽڱȽ�
@return	:	0	��ͬ
			1	��ͬ

@auther :	������
@time	:	2020��4��9��

***********************************************************************/

int memcmp(const void *cs, const void *ct, int count)
{
    const unsigned char *su1, *su2;

    for( su1 = cs, su2 = ct; count > 0; ++su1, ++su2, --count)
    {
        if (*su1 != *su2)
        {
            return 1;
        }
    }
    return 0;
}
/***********************************************************************
function:	�����ַ�������
@param	:	s1		Ŀ������
			s2  	Դ����
			n		����
@other	:    �ú����ǰ��ֽڱȽ�
@return	:	��

@auther :	������
@time	:	2020��4��9��

***********************************************************************/

void *memcpy(void *s1, const void *s2, int n)
{
    const unsigned char *psrc = s2;
    volatile unsigned char *pdst = s1;

    while (n-- > 0)
        *pdst++ = *psrc++;
    return s1;
}
/***********************************************************************
function:	�ַ������ú���
@param	:	s		Ҫ�����õ�����
			c  		����ֵ
			n		����
@other	:    �ú����ǰ��ֽڱȽ�
@return	:	��

@auther :	������
@time	:	2020��4��9��

***********************************************************************/
void *memset(void *s, int c, int count)
{
    unsigned char *xs = (unsigned char *) s;

    while (count--)
        *xs++ = c;
    return s;
}
/***********************************************************************
function:	�ж��ַ���sub_str�Ƿ���str���Ӵ�
@param	:	str			�ַ���
			sub_str		�ַ���
			num			����
@other	:    �ú����ǰ��ֽڱȽ�
@return	:	0	����
			1	��

@auther :	������
@time	:	2020��4��9��

***********************************************************************/
INT8U strstr(const INT8U *str, const INT8U *sub_str, INT8U num)
{
    unsigned char cont = 0;
    const unsigned char *p, *q;

    while(*str != '\0')
    {
        cont = 0;
        p    = str;
        q    = sub_str;
        if(*p == *q)
        {

            while(*p && *q && *p == *q)
            {
                p++;
                q++;
                cont += 1;
                if(cont == num)
                    return 1;
            }

        }
        str++;
    }
    return 0;
}
/***********************************************************************
function:	�ж��ַ���needle �Ƿ�you haystack���ַ���
@param	:	haystack			�ַ���
			needle		�ַ���
@other	:    �ú����ǰ��ֽڱȽ�
@return	:	0	û��
			other ��Ӧ���ַ�

@auther :	������
@time	:	2020��4��9��

***********************************************************************/
char *pstrstr(const char *haystack, const char *needle)
{
    char *cp = (char *)haystack;
    char *s1, *s2;

    if (!*needle)
        return((char *)haystack);

    while (*cp)
    {
        s1 = cp;
        s2 = (char *)needle;
        while(*s1 && *s2 && !(*s1 - *s2))
        {
            s1++;
            s2++;
        }
        if(!*s2)
            return(cp);
        cp++;
    }
    return NULL;
}


char *strchr(const char *s, char c)
{
    if (NULL == s) return NULL;
    while ('0' != *s && c != *s) s++;
    return ('0' == *s) ? NULL : (char *)s;
}

/***********************************************************************
��������:		���ַ���ת��Ϊ����
@param:
			pstr		��Ҫת�����ַ���
@other:     ��
@return:
			0	ת��ʧ��
			1	�ɹ�
***********************************************************************/
int atoi(char *pstr)
{
    int Ret_Integer = 0;
    int Integer_sign = 1;
    if(pstr == NULL)
    {
        return 0;
    }

    if(*pstr == '-')
    {
        Integer_sign = -1;
    }
    if(*pstr == '-' || *pstr == '+')
    {
        pstr++;
    }

    while(*pstr >= '0' && *pstr <= '9')
    {
        Ret_Integer = Ret_Integer * 10 + *pstr - '0';
        pstr++;
    }
    Ret_Integer = Integer_sign * Ret_Integer;

    return Ret_Integer;
}

/***********************************************************************
��������:		������ת��Ϊ�ַ���
@param:
			chWord		����ת���������
			pstr		��Ҫת��������ֵ
@other:     ��
@return:	��
***********************************************************************/
void itoa( char chWord[], int Num)
{
    int i = 0, j;
    char chTemp;
    if(Num == 0)
    {
        chWord[i] = '0' + Num % 10;
        i++;
    }
    while(Num != 0)
    {
        chWord[i] = '0' + Num % 10;
        i++;
        Num = Num / 10;

    }
    chWord[i] = '\0';
    for(j = 0; j < i / 2; j++)
    {
        chTemp = chWord[j];
        chWord[j] = chWord[i - 1 - j];
        chWord[i - 1 - j] = chTemp;
    }
    return ;
}

/***********************************************************************
��������:		�������ַ�������
@param:
			dst		�ַ���
			src		�ַ���
@other:     ��
@return:
			�������Ӻ���ַ�
***********************************************************************/
char *strcat(char *dst, const char *src)
{
    char *d;

    if (!dst || !src)
        return (dst);

    d = dst;
    for (; *d; d++);
    for (; *src; src++)
        *d++ = *src;
    *d = 0;
    return (dst);
}

/***********************************************************************
��������:		�ַ����ȽϺ���
@param:
			dst		�ַ���
			src		�ַ���
@other:     ��
@return:
			0	��ͬ
			1	��ͬ
***********************************************************************/
int strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2++)
        if (*s1++ == 0)
            return (0);
    return (*(const unsigned char *)s1 - * (const unsigned char *)--s2);
}

/***********************************************************************
��������:		�ַ�������
@param:
			dest	Ŀ���ַ���
			src		Դ�ַ���
@other:     ��
@return:
			0	ת��ʧ��
			1	�ɹ�
***********************************************************************/
char *strcpy(char *dest, const char *src)
{
    char *r = dest;
    while((*dest++ = *src++) != '\0');
    return r;
}

/***********************************************************************
��������:		�����ַ�������
@param:
			p		Ҫ���������
@other:     �ú����ǰ��ֽڱȽ�
@return:	��
***********************************************************************/
int strlen(const char *p)
{
    int len = 0;
    while(*p++)
        len++;
    return len;
}


int isContained(const char *str, char c)
{
    if (str == NULL)
    {
        return 0;
    }
    const char *p = str;
    while (*p != '\0')
    {
        if (*p == c)
        {
            return 1;
        }
        p++;
    }
    return 0;
}
char *strtok_r(char *str, const char *sep, char **lasts)
{
    char *str_return = NULL;		 //���ص��ַ���
    const char *ctrl = sep; //�ָ���


    if (sep == NULL)
    {
        return NULL;
    }


    if (str == NULL && *lasts == NULL)
    {
        return NULL;
    }


    //���ָ�������map��
    char map[255] = {0};
    int len = 0;
    while (*ctrl != '\0')
    {
        if (isContained(map, *ctrl))
        {
            continue;
        }
        map[len] = *ctrl;
        len++;
        ctrl++;
    }

    if (str == NULL)
    {
        str_return = *lasts;
    }
    else
    {
        str_return = str;
    }

    //���Ե��ַ�������ʼ���ֵķָ���,�ҵ���һ�����Ƿָ������ַ�ָ��
    while(*str_return != '\0')
    {
        if (isContained(map, *str_return))
        {
            str_return++;
            continue;
        }
        break;
    }

    str = str_return;

    //���ҵ�һ���ָ���
    while (*str_return)
    {
        if (isContained(map, *str_return))
        {
            *str_return++ = '\0'; //���ҵ�ʱ����ƥ���ַ���Ϊ0�����Ұ�strָ����һλ
            break;
        }
        str_return++;
    }
    *lasts = str_return; // ��ʣ���ַ�����ָ�뱣�浽��̬����last

    if (str == str_return)
    {
        *lasts = NULL;
        return NULL;
    }
    else
    {
        return str;
    }
}

/*
 * 16����ת�ַ���
 * @param
 * 	dest	ת�������ָ��
 * 	src	��ת���������ַ�ָ��
 * 	len	��ת�������ݳ���
 */
// void hex_to_str(INT8U *dest, INT8U *src, INT8S len)
// {
//     INT32S i;
//     for (i = 0; i < len; i++)
//     {
//         sprintf((INT8S *)dest + i * 2, "%02x", *(src + i));
//     }

// }

/*
 * �ַ���ת16����
 * @param
 * 	hex	ת����16�������ָ��
 * 	dsp	��ת���������ַ�ָ��
 * 	len	��ת�������ݳ���
 */
void str_to_hex(INT8U *hex, INT8U *dsp, INT8S len)
{
    int i, j;
    for (i = 0; i < len / 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            hex[i] |= dsp[i * 8 + j] << (8 - j);
        }
    }
}

/*
 * 16����תASCII������ֵ
 * @param
 * 	str	��ת���������ַ�ָ��
 * @return
 * 	int	���ASCII������ֵ
 */
int atohex(char *str)
{
    int singleResult = 0;
    int totalResult = 0;
    INT8U i, j;
    INT8U lenth = strlen(str);
    for(i = 0; i < lenth; i++)
    {
        singleResult = str[i];
        if ((singleResult >= '0') && (singleResult <= '9'))
        {
            singleResult = (str[i] - '0');

        }
        else
        {
            if ((singleResult >= 'a') && (singleResult <= 'f'))
            {
                singleResult = (str[i] - 'a') + 10;
            }
            else
            {
                if ((singleResult >= 'A') && (singleResult <= 'F'))
                {
                    singleResult = (str[i] - 'A') + 10;
                }
                else
                {
                    return 0;

                }

            }
        }

        for (j = 0; j < (lenth - 1 - i); j++)
        {
            singleResult = singleResult * 16;
        }
        totalResult += singleResult;
    }
    return totalResult;
}
int strncmp(const char *s1, const char *s2, size_t n)
{
    if (n == 0)
        return 0;

    // initial
    while (n-- != 0 && *s1 == *s2)
    {
        if (n == 0 || *s1 == '\0')
            break;
        s1++;
        s2++;
    }
    // initial

    // my
	//while (--n && *s1 && *s1 == *s2) // ??????????????\0????????????????? n = 0 ????
	//{
		//s1++;
		//s2++;
    //}
    // my

    return (*(unsigned char *) s1) - (*(unsigned char *) s2);
}



