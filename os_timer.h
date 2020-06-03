#ifndef OS_TIMER_H
#define OS_TIMER_H
#pragma pack(1)
typedef struct
{
  char TimerName[8];
	unsigned char TimerId;
  unsigned char TimerAble;
  unsigned long TimerCount;
  unsigned long TimerSetVal;
  //void *param;
  //void (*ptimer_fun)(void);
	void (*pfun)(void);
}TIMER_CLASS;
#pragma pack()
extern volatile unsigned long gTick;
#define GTICK_ADDAUTO() gTick++
char timer_run(void);
char timer_creat(char *ptimername,unsigned short cTimer_interval,unsigned char cAble,void (*pfun)(void));
void timer_enable(unsigned char cTimer_id);
void timer_disable(unsigned char cTimer_id);
char get_time_id(char *pTimerName);
#endif 
