#pragma once
#include<stdio.h>
#include<windows.h>

typedef char datalinktype;
typedef struct node {
	datalinktype data;
	struct node* next;
}stacknode,*linkstack;

//��ʼ��
void initlinkstack(linkstack *s)
{
	*s = (linkstack)malloc(sizeof(stacknode));
	if(*s==NULL)
	{
		exit(-1);
	}
	(*s)->next = NULL;
}

//�п�
int linkstackempty(linkstack s)
{
	if (s->next == NULL)
		return 1;
	else
		return 0;
}

//��ջ
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

//��ջ
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