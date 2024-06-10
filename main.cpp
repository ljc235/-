#include<stack.h>
#include<stacklink.h>
//À¨ºÅÆ¥Åäº¯Êý
void bracket(stack *s,char ch)
{
	char c;
	switch (ch)
	{
	case '(':
	case '[':
	case '{':
		push(s, ch);
	}
	if (ch == ')' && s->data[s->top - 1] == '(')
		pop(s, &c);
	if (ch == ']' && s->data[s->top - 1] == '[')
		pop(s, &c);
	if (ch == '}' && s->data[s->top - 1] == '{')
		pop(s, &c);
}

//Á´Ê½Õ»À¨ºÅÆ¥Åä
void linkbracket(linkstack s, char ch)
{
	char c;
	switch (ch)
	{
	case '(':
	case '[':
	case '{':
		pushstack(s, ch);
	}
	if (ch == ')' && s->next->data == '(')
		popstack(s, &c);
	if (ch == ']' && s->next->data == '[')
		popstack(s, &c);
	if (ch == '}' && s->next->data == '{')
		popstack(s, &c);
}
void main()
{
	//Á´Ê½Õ»²âÊÔ
	/*
	linkstack s;
	initlinkstack(&s);
	char ch;
	ch = getchar();
	while (ch != '#')
	{
		pushstack(s, ch);
		ch = getchar();
	}

	while (s!=NULL)
	{
		popstack(s, &ch);
		printf("%c\n", ch);
	}
	*/

	//Á´Ê½Õ»À¨ºÅÆ¥Åä
	linkstack s;
	int i=0;
	char ch[20];
	char nu;
	scanf("%s", &ch);
	initlinkstack(&s);
	while (ch[i])
	{
		linkbracket(s, ch[i]);
		i++;
	}
	if (linkstackempty(s))
		printf("À¨ºÅÆ¥Åä³É¹¦£¡");
	else
		printf("À¨ºÅÆ¥ÅäÊ§°Ü£¡");

	//À¨ºÅÆ¥Åä
	/*
	stack s;
	int i=0;
	char ch[20];
	char nu;
	scanf("%s", &ch);
	initstack(&s);
	while (ch[i])
	{
		bracket(&s, ch[i]);
		i++;
	}
	if (isempty(s))
		printf("À¨ºÅÆ¥Åä³É¹¦£¡");
	else
		printf("À¨ºÅÆ¥ÅäÊ§°Ü£¡");
	*/

	/*Ë³ÐòÕ»²âÊÔ
	stack s;
	initstack(&s);
	char ch;
	ch = getchar();
	while(ch!='#')
	{
		push(&s, ch);
		ch = getchar();
	}
	
	while (s.top>0)
	{
		pop(&s, &ch);
		printf("%c\n", ch);
	}
	*/
}