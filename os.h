#ifndef OS_H
#define OS_H


#pragma pack(1)
typedef struct
{
	 // char            cOwnname[TASK_NAME_LEN]
		//char 						cOthername[TASK_NAME_LEN];
		unsigned char 	cIsonce[1];
} TASK_PARAM_CLASS;
#pragma pack()
typedef struct
{
  unsigned char TaskId;
  char TaskDes[TASK_NAME_LEN];
	unsigned char EnTask;
unsigned long TaskCount;
unsigned long TaskLineNum;
	void (*task_fun)(void);
}TASK_CLASS;
extern volatile TASK_CLASS   gTaskClass[MAX_TASK_COUNT];
#define LINENUMGET(num) num=__LINE__;case __LINE__:
#define TASK_BEGINE(taskid)	switch(gTaskClass[taskid].TaskLineNum){ case 0:
#define TASK_DEALY(taskid,Nms) do { \
						gTaskClass[taskid].TaskCount = gTick;\
						LINENUMGET(gTaskClass[taskid].TaskLineNum);\
						if(gTick - gTaskClass[taskid].TaskCount > Nms)\
						{ \
							gTaskClass[taskid].TaskLineNum=0;\
							break;\
						}\
						return;\
						}while(0)
#define TASK_WHILE(taskid) do{\
							LINENUMGET(gTaskClass[taskid].TaskLineNum);\
							}while(0)
#define TASK_END() }
#define TASK_EXIT(taskid)  if(1)\
						 {\
					 		gTaskClass[taskid].TaskLineNum=0;\
					 		break;\
                         }

char os_creat(char *pdes,unsigned char en_task,void (*task_fun)(void));
void endis_task(unsigned char cmTask_id,unsigned char enordis);
unsigned char get_task_status(unsigned char cmTaskId);
unsigned long cur_tickval(void) ;
void endis_task(unsigned char cmTaskId,unsigned char EnOrDis);
unsigned char get_task_status(unsigned char cmTaskId);
void get_now_task(char *pdes);
unsigned char get_now_taskid(void);
char get_task_id(char *pTaskDes);
#endif

