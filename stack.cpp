#include<stdio.h>
#include<malloc.h>
#include <string.h>
#define OK 1
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef char ElemType;
typedef int Status;
typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

SqStack s;

Status InitStack_Sq() {
	s.base = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!s.base) printf("ø’º‰∑÷≈‰ ß∞‹");
	s.top = s.base;
	s.stacksize = LIST_INIT_SIZE;
	return OK;
}//INIT

Status PrintStack() {
	if (s.top = s.base) {
		printf("666");
	}
	else printf("777");
	/*for (unsigned int i = 0; i < ; i++)
		printf("%c", s.base[i]);*/
	return 0;
}//Print

Status Push(ElemType e) {
	if (s.top - s.base >= s.stacksize) {
		s.base = (ElemType *)realloc(s.base, (s.stacksize + LISTINCREMENT) * sizeof(ElemType));
		if (!s.base) printf("ø’º‰∑÷≈‰ ß∞‹");
		s.top = s.base + s.stacksize;
		s.stacksize += LISTINCREMENT;
	}
	*s.top++ = e;
	return 0;
}//PUSH

Status Pop(ElemType *e) {
	if (s.top == s.base) printf("≥ˆ’ª ß∞‹");
	*e = *--s.top;
	return 0;
}//POP

Status GetTop(ElemType *e) {
	if (s.top == s.base) printf("µ√µΩ’ª∂•‘™Àÿ ß∞‹");
	*e = *(s.top - 1);
	return 0;
}

int brackets(ElemType *ch) {
	char c[] = "{";
	for (unsigned int i = 0; i < strlen(ch); i++)
	{
		if (ch[i] == c[0])
		{
			Push(ch[i]);
		}
		else
		{
			if (s.top == s.base)
			{
				printf("”“¿®∫≈∂‡”‡");
				return 0;
			}
			else
			{
				ElemType e;
				GetTop(&e);
				//printf("e:%c", e);
				//printf("%c", ch[i]);
				if (c[0] == e)
				{
					Pop(&e);//PopStack();
				}
				else
				{
					printf("≤ª∆•≈‰");
				}
			}
		}
	}
	if (s.top == s.base)
	{
		printf("∆•≈‰’˝»∑");
	}
	else
	{
		printf("◊Û¿®∫≈”–”‡");
	}
	
}//Brackets

void printch(char *a) {
	for (unsigned int i = 0; i < strlen(a); i++)
		printf("%c\n", a[i]);
}//printch

void main() {
	char ch[50];
	printf("«Î ‰»Îƒ„“™∆•≈‰µƒ◊÷∑˚¥Æ:");
	gets_s(ch);//scanf_s("%s", &ch);
	//printf("%d\n", strlen(ch));
	//printch(ch);
	InitStack_Sq();
	brackets(ch);
	getchar();
}