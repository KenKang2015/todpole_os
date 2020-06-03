/**********************************************************************************************************
*filename:
*description:
*Active:
*AUther:
*   All right of Ken
*********************************************************************************************************/
#include "stdio.h"
#include "string.h"

#include "osconfig.h"
#include "os_timer.h"
#include "os.h"
//typedef void (*posFUN)(LED_STATUS_TYPE);


volatile TASK_CLASS   gTaskClass[MAX_TASK_COUNT];
volatile unsigned char gNowTaskId=0;
volatile unsigned char gNowTaskIdCount =0;
//volatile char gTaskDescriptionArray[MAX_TASK_COUNT][TASK_NAME_LEN];

/******************************************************************************************************
*function:
*description:
*input:
*output:
******************************************************************************************************/
#if 0
/******************************************************************************************************
*function:
*description:
*input:
*output:
*******************************************************************************************************/
 char conncet_to(unsigned char cRec_id,unsigned char cIsmg,unsigned char *pdata,unsigned char cmMsgtype,unsigned short datalen)
{
 unsigned char i;
	T_INFO_DATA output_msg;
 if( cRec_id >= MAX_TASK_COUNT)
		return -1;
	if( cRec_id != task_class[cRec_id].task_id)
		return -1;
	task_class[cRec_id].en_task =1;
	output_msg.type = cmMsgtype;
	output_msg.len = datalen;
	memcpy(output_msg.buf,pdata,datalen);
	if(cIsmg) Recv_queue_fun(INPUT,&output_msg,task_class[cRec_id].input_msg);
  task_class[cRec_id].ismsg = cIsmg;
	
		return 0;
}
/****************************************************************************************************
*function:
*description:
*input:
*output:
******************************************************************************************************/
char conncet_from(unsigned char cRec_id, unsigned char *outmsg,unsigned short *datalen,unsigned char *msgtype)
{
	T_INFO_DATA output_msg;
	if( task_class[cRec_id].ismsg == 0)
		return -1;
	Recv_queue_fun(OUTPUT,&output_msg,task_class[cRec_id].input_msg);
	*datalen = output_msg.len;
	*msgtype = output_msg.type;
	memcpy(outmsg,output_msg.buf,output_msg.len);
	return 0;
}
#endif
/*******************************************************************************************************
*function:
*description:
*input:
*output:
*******************************************************************************************************/
 char os_creat(char *pdes,unsigned char en_task,void (*task_fun)(void))
{
 if(gNowTaskId >= MAX_TASK_COUNT)
   return (char)-1;
	if(strlen(pdes) > 8)
		return (char)-2;
  gTaskClass[gNowTaskId].TaskId = gNowTaskId;
	strcpy((char*)gTaskClass[gNowTaskId].TaskDes,pdes);
//	memset((unsigned char*)task_class[now_task_id].input_msg,0,sizeof(T_INFO_DATA)*MAX_LEN_MSG);
//	memset((unsigned char*)&task_class[now_task_id].output_msg,0,sizeof(T_INFO_DATA));
	//task_class[now_task_id].ismsg =0;
	gTaskClass[gNowTaskId].EnTask = en_task;
//	gTaskClass[gNowTaskId].pconnect = conncet;
	gTaskClass[gNowTaskId].task_fun = task_fun;
	gTaskClass[gNowTaskId].TaskCount = 0;
	gTaskClass[gNowTaskId].TaskLineNum =0;
	//task_class[gNowTaskId].ptask_param_struct = pTask_param_class;
	//strcpy((char*)gTaskDescriptionArray[gNowTaskId]  ,pdes);
	gNowTaskId++;
	return 0;
}
/******************************************************************************************************
*function:
*description:
*input:
*output:
*****************************************************************************************************/
 char get_task_id(char *pTaskDes)
{
	unsigned char i;
	for(i =0;i < MAX_TASK_COUNT;i++)
	{
		if(0==strcmp((char*)gTaskClass[i].TaskDes,pTaskDes))
			break;
	}
	if(i ==MAX_TASK_COUNT)
		return (char)-1;
	return i;
}
/*******************************************************************************************************
*function:
*description:
*input:
*output:
*******************************************************************************************************/
void endis_task(unsigned char cmTaskId,unsigned char EnOrDis)
{
	gTaskClass[cmTaskId].EnTask = EnOrDis;
}
/***************************************************************************************************
*function:
*description:
*input:
*output:
**************************************************************************************************/
unsigned char get_task_status(unsigned char cmTaskId)
{
	 return gTaskClass[cmTaskId].EnTask;
}
/*******************************************************************************************************
*function:
*description:
*input:
*output:
*********************************************************************************************************/
void os_run(void (*pFunWeed)())
{
	
	gNowTaskIdCount= 0;
	while(1)
	{
		if(gTaskClass[gNowTaskIdCount].EnTask){
			
				gTaskClass[gNowTaskIdCount].task_fun();
		}
		gNowTaskIdCount++;
		if(gNowTaskIdCount >=gNowTaskId)
			gNowTaskIdCount = 0;
		timer_run();
		if(pFunWeed !=NULL)
			pFunWeed();
	}
	
	
	 
}
/*********************************************************************************************************************************
*function:
*description:
*input:
*output:
**********************************************************************************************************************************/
void get_now_task(char *pdes)
{
	strcpy(pdes,(char*)gTaskClass[gNowTaskIdCount].TaskDes);
}
/*******************************************************************************************************************
*function:
*description:
*input:
*output:
********************************************************************************************************************/
unsigned char get_now_taskid(void)
{
	return gTaskClass[gNowTaskIdCount].TaskId;
}
