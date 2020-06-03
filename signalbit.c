/****************************************************************************************************
*filename:signalbit
*description:
*active:
*auther:
*date:
*all right
*****************************************************************************************************/
#include "osconfig.h"
#include "signalbit.h"
volatile BITMAP_STRUCT gBitMapClass;
/*****************************************************************************************************
*function:
*description:
*input:
*output:
*******************************************************************************************************/
void signalbit_Init()
{
	gBitMapClass.TaskBitMap=0;
	gBitMapClass.TimerTaskBitMap=0;
		
	
}
/********************************************************************************************************
*function:
*description:
*input:
*output:
*********************************************************************************************************/
int signalbit_gettaskid(void)
{

	unsigned char cTmpId=0;
 	if(0==gBitMapClass.TaskBitMap) return -1;
  	while(gBitMapClass.TaskBitMap !=0)
 	{
   		if((gBitMapClass.TaskBitMap & (1 << cTmpId)) !=0)
			break;
		cTmpId++;
  	}
	SIGNALBIT_CLR(cTmpId);
	return cTmpId;
}
int signalbit_gettimertaskid(void)
{
	unsigned char cTmpId=0;
 	if(0==gBitMapClass.TimerTaskBitMap) return -1;
  	while(gBitMapClass.TimerTaskBitMap !=0)
 	{
   		if((gBitMapClass.TimerTaskBitMap & (1 << cTmpId)) !=0)
			break;
		cTmpId++;
  	}
	SIGNALTIMERBIT_CLR(cTmpId);
	return cTmpId;
}

