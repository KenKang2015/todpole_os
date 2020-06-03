#include "queue.h"

T_INFO_DATA recv_queue[MAX_QUEUE];
#ifdef EN_SEND_QUEUE
T_INFO_DATA send_queue[MAX_QUEUE];
#endif


int recv_rear=0,recv_front=0;  //rear 添加计数  front取出计数

#ifdef EN_SEND_QUEUE
int send_rear=0,send_front=0; 
#endif 

//int Recv_queue_fun(Queue_Action_TypeDef action,T_INFO_DATA * msg);

#ifdef EN_SEND_QUEUE
int Send_queue_fun(Queue_Action_TypeDef action,T_INFO_DATA * msg);
#endif

//添加
int EnQueue(T_INFO_DATA *Q,T_INFO_DATA x,int *pf,int *pr)
{
	int front,rear;
    
	front=*pf;
	rear=*pr;
	if((rear+1)%MAX_QUEUE==front)
		return 0;
	else
	{
		Q[rear]=x;
		rear = (rear+1)%MAX_QUEUE;
		*pr=rear;
		return 1;
	}
	
}

//取出
int DeQueue(T_INFO_DATA *Q,T_INFO_DATA *py,int *pf,int *pr)
{
	int front,rear;
	front=*pf;
	rear=*pr;
	if(front==rear)
		return 0;
	else
	{
		*py=Q[front];
		front=(front+1)%MAX_QUEUE;
		*pf=front;
		return 1;	
	}	
}

int Recv_queue_fun(Queue_Action_TypeDef action,T_INFO_DATA *msg,T_INFO_DATA *inmsg)
{
	int ret=0;
	//pthread_mutex_lock(&mutex_recv_queue);//上锁
	if(action==INPUT)
	{
		ret=EnQueue(inmsg,*msg,&recv_rear,&recv_front);
	}
	else
	{
		ret=DeQueue(inmsg,msg,&recv_rear,&recv_front);
	}
	//pthread_mutex_unlock(&mutex_recv_queue);//解锁
	return ret;	
}

#ifdef EN_SEND_QUEUE
int Send_queue_fun(Queue_Action_TypeDef action,T_INFO_DATA * msg)
{
	int ret=0;
	//pthread_mutex_lock(&mutex_send_queue);//上锁
	if(action==INPUT)
	{
		ret=EnQueue(send_queue,(*msg),&send_rear,&send_front);
	}
	else
	{
		ret=DeQueue(send_queue,msg,&send_rear,&send_front);
	}
	//pthread_mutex_unlock(&mutex_send_queue);//解锁
	return ret;
}
#endif

