#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAX_BUFF_LEN   2
#define MAX_QUEUE      5                   //���Ļ���������

typedef struct //������Ϣ�Ľṹ
{
	unsigned char type;//ʲô���͵���Ϣ
    unsigned char len; //��Ϣ����
    unsigned char buf[MAX_BUFF_LEN];    
}T_INFO_DATA; 


typedef enum {
INPUT  =0,  
OUTPUT,
}Queue_Action_TypeDef;


extern T_INFO_DATA recv_queue[MAX_QUEUE];

//#define EN_SEND_QUEUE     1             //ʹ�ܷ��Ͷ���
              
#ifdef EN_SEND_QUEUE
extern T_INFO_DATA send_queue[MAX_QUEUE];
extern int send_rear,send_front;
#endif

extern int recv_rear,recv_front;

int EnQueue(T_INFO_DATA *Q,T_INFO_DATA,int *pf,int *pr);       //�������
int DeQueue(T_INFO_DATA *Q,T_INFO_DATA *py,int *pf,int *pr);   //ȡ������
int Recv_queue_fun(Queue_Action_TypeDef action,T_INFO_DATA *msg,T_INFO_DATA *inmsg);

#ifdef EN_SEND_QUEUE
int Send_queue_fun(Queue_Action_TypeDef action,T_INFO_DATA * msg);
#endif

#endif

