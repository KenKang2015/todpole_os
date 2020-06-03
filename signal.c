/***************************************************************************************************
*filename: signal.c
*description:
*active:
*auther:
*date:
* all right of ken
*****************************************************************************************************/
#include "stdio.h"
#include "string.h"
#include "osconfig.h"
#include "os.h"
#include "os_timer.h"
#include "signal.h"
volatile SIGNAL_STRUCT *gSignalAddrArray[MAX_COUNTAINER_NUM];
volatile unsigned short gSignalAddrNum=0;

/****************************************************************************************************
*function:
*description:
*input:
*output:
*****************************************************************************************************/
void signal_containerinit()
{
	unsigned short i;
	for(i=0;i< MAX_COUNTAINER_NUM;i++)
	{
		gSignalAddrArray[i]=NULL;
	}
	gSignalAddrNum =0;
	
}
/****************************************************************************************************
*function:
*description:
*input:
*output:
****************************************************************************************************/
static void  signal_container(SIGNAL_STRUCT *pSingnalClass)
{
	gSignalAddrArray[gSignalAddrNum++] = pSingnalClass;
}

/****************************************************************************************************
*function:
*description:
*input:
*output:
****************************************************************************************************/
void signal_creat(SIGNAL_STRUCT *pSingnalClass)
{
 	//pSingnalClass->OriginTaskId=cOriginTaskId;
 	//pSingnalClass->TargetTaskId= cTargetTaskId;
	pSingnalClass->SignalFlag=0;
	pSingnalClass->SignalLenOrNum =0;
	pSingnalClass->pBuffer=NULL;
	signal_container(pSingnalClass);
}
/****************************************************************************************************
*function:
*description:
*input:
*output:
*****************************************************************************************************/
unsigned char signal_send(SIGNAL_STRUCT *pSingnalClass,unsigned long cLenOrNum,unsigned char *pBuffer)
{
	if(pSingnalClass->SignalFlag==1)return 0;
	pSingnalClass->SignalFlag=1;
	pSingnalClass->SignalLenOrNum =cLenOrNum;
	pSingnalClass->pBuffer=pBuffer;
	return 1;
}
/*****************************************************************************************************
*function:
*description:
*input:
*output:
****************************************************************************************************/
unsigned char signal_rec(SIGNAL_STRUCT *pSingnalClass,unsigned long *pLen,unsigned char **pBuffer)
{
	if(0==pSingnalClass->SignalFlag) return 0;
	if(NULL != pSingnalClass->pBuffer)
	{
		//memcpy((unsigned char*)pBuffer,(unsigned char*)pSingnalClass->pBuffer,pSingnalClass->SignalLenOrNum);
		*pBuffer=pSingnalClass->pBuffer;
	}
	*pLen = pSingnalClass->SignalLenOrNum;
	//pSingnalClass->pBuffer=NULL;
	pSingnalClass->SignalFlag = 0;
	pSingnalClass->SignalLenOrNum =0;
	return 1;
	
}
/***************************************************************************************************
*function:
*description:
*input:
*output:
****************************************************************************************************/
SIGNAL_STRUCT *signal_containercheck()
{
    unsigned char iPos=0;
	while(gSignalAddrArray[iPos] !=NULL)
	{
		if(gSignalAddrArray[iPos]->SignalFlag ==1)
			return (SIGNAL_STRUCT *)gSignalAddrArray[iPos];
	}
	return NULL;
	
}
