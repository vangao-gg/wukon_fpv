#ifndef __CONSOLE_H
#define __CONSOLE_H
#include <stdbool.h>
#include "sys.h"

/********************************************************************************	 
 * ������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
 * ATKflight�ɿع̼�
 * ���ݴ�ӡ��������	
 * ����ԭ��@ALIENTEK
 * ������̳:www.openedv.com
 * ��������:2018/5/2
 * �汾��V1.0
 * ��Ȩ���У�����ؾ���
 * Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
 * All rights reserved
********************************************************************************/

void consoleInit(void);
bool consoleTest(void);
int consolePutchar(int ch);	/* ����һ���ַ���console������*/
int consolePutcharFromISR(int ch);	/* �жϷ�ʽ����һ���ַ���console������*/
int consolePuts(char *str);	/* ����һ���ַ�����console������*/

#endif /*__CONSOLE_H*/