/*******************************************************************************************************************
*filename:
*description:
*actvie:
*auther:
*date:
* all rigth
******************************************************************************************************************/
#include "stdio.h"
#include "string.h"

#include "osconfig.h"
#include "os_timer.h"
#include "os.h"
#include "irqlisten.h"
volatile unsigned char gListenFunCount=0;
volatile void (*plistenfun[MAX_FUN_NUM])(void);

/****************************************************************************************************************
*function:
*description:
*input:
*output:
****************************************************************************************************************/
void os_listen_add(void (*pfun)(void))
{
  unsigned char i;
  for(i=0;i<MAX_FUN_NUM;i++)
  {
    if(plistenfun[i] ==NULL)
    break;
  }
  if(i >= MAX_FUN_NUM) return;
  plistenfun[i]=pfun;
  
}
/**************************************************************************************************************
*function:
*description:
*input:
*output:
*****************************************************************************************************************/
void os_listen_desctory(void (*pfun)(void))
{
  unsigned char i;
  for(i=0;i<MAX_FUN_NUM;i++)
  {
    if(plistenfun[i] ==pfun)
    break;
  }
  if(i >= MAX_FUN_NUM) return;
  plistenfun[i]=NULL;
  
}
   
/***************************************************************************************************************
*function:
*description:
*input:
*output:
**************************************************************************************************************/
void os_listen_init()
{
    unsigned char i;
  for(i=0;i<MAX_FUN_NUM;i++)
  {
    plistenfun[i] =NULL;
   
  }
}
                            
                   