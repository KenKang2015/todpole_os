#ifndef IRQLISTEN_H
#define IRQLISTEN_H
void os_listen_init(void);
void os_listen_add(void (*pfun)(void));
void os_listen_desctory(void (*pfun)(void));
#endif
