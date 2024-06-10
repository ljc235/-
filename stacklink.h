#pragma once
#include<stdio.h>
#include<windows.h>

typedef char datalinktype;
typedef struct node {
	datalinktype data;
	struct node* next;
}stacknode,*linkstack;

//初始化
void initlinkstack(linkstack *s)
{
	*s = (linkstack)malloc(sizeof(stacknode));
	if(*s==NULL)
	{
		exit(-1);
	}
	(*s)->next = NULL;
}

//判空
int linkstackempty(linkstack s)
{
	if (s->next == NULL)
		return 1;
	else
		return 0;
}

//入栈
void pushstack(linkstack s, char ch)
{
	linkstack p;
	p = (stacknode*)malloc(sizeof(stacknode));
	if (p != NULL)
	{
		p->data = ch;
		p->next = s->next;
		s->next = p;
	}
}

//出栈
void popstack(linkstack s, char* ch)
{
	linkstack p;
	p = s->next;
	if (linkstackempty(s))
	{
		printf("Stack is empty!");
		exit(-1);
	}
	*ch = p->data;
	s->next = p->next;
	free(p);
}