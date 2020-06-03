#ifndef SIGNAL_BIT_H
#define SIGNAL_BIT_H
#if SMALLBITMODE
	typedef unsigned long BITMAP;
#else
	typedef unsigned long long BITMAP;
#endif
typedef struct
{
	BITMAP TaskBitMap;
	BITMAP TimerTaskBitMap;
}BITMAP_STRUCT;
extern volatile BITMAP_STRUCT gBitMapClass;
#define SIGNALBIT_SET(taskid) do{ \
								 gBitMapClass.TaskBitMap |= 1<<taskid;\
								 }while(0)
#define SIGNALBIT_CLR(taskid)    do{\
								 	 gBitMapClass.TaskBitMap &= ~(1<<taskid);\
									}while(0)
#define SIGNALTIMERBIT_SET(taskid) do{ \
									 gBitMapClass.TimerTaskBitMap |= 1<<taskid;\
									 }while(0)
#define SIGNALTIMERBIT_CLR(taskid)    do{\
										 gBitMapClass.TimerTaskBitMap &= ~(1<<taskid);\
										}while(0)
extern void signalbit_init(void);
extern int signalbit_gettaskid(void);
extern int signalbit_gettimertaskid(void);




#endif
