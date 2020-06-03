#ifndef SIGNAL_H
#define SIGNAL_H
//#pragma pack(1)
typedef struct
{
 //unsigned char	OriginTaskId;
 //unsigned char 	TargetTaskId;
 unsigned char	SignalFlag;
 unsigned long  SignalLenOrNum;
 unsigned char  *pBuffer;
}SIGNAL_STRUCT;
//#pragma pack()
void signal_containerinit(void);

void signal_creat(SIGNAL_STRUCT *pSingnalClass);
unsigned char signal_send(SIGNAL_STRUCT *pSingnalClass,unsigned long cLenOrNum,unsigned char *pBuffer);
unsigned char signal_rec(SIGNAL_STRUCT *pSingnalClass,unsigned long *pLen,unsigned char **pBuffer);



#endif
