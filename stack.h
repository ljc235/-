#pragma once
#include<stdio.h>
#include<Windows.h>
#define MAXSIZE 20

typedef char datatype;
typedef struct stackstr
{
	datatype data[MAXSIZE];
	int top;

}stack;

//��ʼ��
void initstack(stack* s)
{
	s->top = 0;
}

//�п�
int isempty(stack s)
{
	return s.top == 0 ? 1 : 0;
}
//��ջ
void push(stack* s,datatype ch)
{
	if (s->top == MAXSIZE)
	{
		printf("Stack is full!");
		exit(-1);
	}
	s->data[s->top] = ch;
	s->top++;
}

//��ջ
void pop(stack* s, datatype* ch)
{
	if (isempty(*s))
	{
		printf("Stack is empty!");
		exit(-1);
	}
	s->top--;
	*ch=s->data[s->top];
}