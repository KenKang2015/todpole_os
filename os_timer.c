/**********************************************************************************************************
*filename:
*description:
*active:
*atuher:
*Date:
*     all right @ ken
************************************************************************************************************/
#include"stdio.h"
#include "string.h"
#include "osconfig.h"

#include "os.h"
#include "os_timer.h"


/********************************************************************
* 功能 : 返回当前1ms Tick
* 输入: 
* 输出: 
* 全局变量: 
*
* 备注: (修改记录内容、时间)
********************************************************************/




volatile unsigned long gTick;
unsigned long cur_tickval(void) ;                // 返回当前1ms Tick
volatile TIMER_CLASS gTimerClass[MAX_TIMER_ID_COUNT];
volatile unsigned char gNowTimerCount =0;
unsigned char gNowTimerId = 0;
/********************************************************************
* 功能 : 返回当前1ms Tick
* 输入: 
* 输出: 
* 全局变量: 
*
* 备注: (修改记录内容、时间)
********************************************************************/
unsigned long cur_tickval(void) 
{
	return gTick;
}
/***************************************************************************
*function:
*description:
*input:
*output:
****************************************************************************/
char timer_run()
{
	unsigned long cNowTimer;
		//LCD_WriteRam0_7Int32(1,UAR_La[5]);
	if(gNowTimerCount >=MAX_TIMER_ID_COUNT)
		return (char)-1;
	if(gTimerClass[gNowTimerCount].TimerAble ==1)
	{
			cNowTimer = cur_tickval();
	if((cNowTimer - gTimerClass[gNowTimerCount].TimerCount) >= gTimerClass[gNowTimerCount].TimerSetVal)
	{
		
		 gTimerClass[gNowTimerCount].TimerCount = /*timer_class[now_timer_count].timer_setval+*/ cur_tickval();
	    gTimerClass[gNowTimerCount].pfun();
    // ddadd++;
	
	}
	}
	
	
	gNowTimerCount++;
	if(gNowTimerCount >= gNowTimerId)
	{
		gNowTimerCount = 0;
	}
	return 1;
}
/**************************************************************************8
*function:
*description:
*input:
*output:
********************************************************************************/
char timer_creat(char *pTimerName,unsigned short cTimerInterval,unsigned char cAble,void (*pfun)(void))
{
  if(pTimerName == NULL)
	  return (char)-1;
	if(gNowTimerId >= MAX_TIMER_ID_COUNT)
		return (char)-1;
	strcpy((char*)gTimerClass[gNowTimerId].TimerName,pTimerName);
//	gTimerClass[cTimer_id].timer_id = cTimer_id;
	gTimerClass[gNowTimerId].TimerAble= cAble;
	gTimerClass[gNowTimerId].TimerSetVal = cTimerInterval;
	gTimerClass[gNowTimerId].TimerCount = gTick ;//+ timer_class[now_timer_id].timer_setval;
	gTimerClass[gNowTimerId].pfun = pfun;
//	gTimerClass[now_timer_id].param = param;
	//timer_class[cTimer_id].ptimer_fun = timer_run;
	gNowTimerId++;
	return 0;
}
/**********************************************************************
*function:
*description:
*input:
*output:
*********************************************************************/
char get_time_id(char *pTimerName)
{
	unsigned char i;
	for(i =0;i < MAX_TIMER_ID_COUNT;i++)
	{
		if(0==strcmp((char*)gTimerClass[i].TimerName,pTimerName))
			break;
	}
	if(i ==MAX_TIMER_ID_COUNT)
		return (char)-1;
	return i;
}
/********************************************************************************
*function:
*description:
*input:
*output:
**********************************************************************************/
void timer_enable(unsigned char cTimeId)
{
	//if(get_time_id(char *pTimer_des))
	if(gTimerClass[cTimeId].TimerAble == 1)
		return;
	gTimerClass[cTimeId].TimerCount= cur_tickval();
  gTimerClass[cTimeId].TimerAble = 1;
}
/**********************************************************************************
*function:
*description:
*iniput:
*output:
**********************************************************************************/
void timer_disable(unsigned char cTimerId)
{
	gTimerClass[cTimerId].TimerAble =0;
}
/********************************************************************************
*function:
*description:
*input:
*output:
************************************************************************************/
unsigned char timer_get_status(unsigned char cTimerId)
{
	return gTimerClass[cTimerId].TimerAble;
}
