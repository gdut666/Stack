#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

Status initLStack(LinkStack *s) {
	Status ret = ERROR;
	if (s) {
		ret = SUCCESS;
		s->top = NULL;
		s->count = 0;
	}
	return ret;
}

Status isEmptyLStack(LinkStack *s) {
	Status ret = ERROR;
	if (s->top == NULL) ret = SUCCESS;
	return ret;
}

Status getTopLStack(LinkStack *s,ElemType *e) {
	Status ret = ERROR;
	if (s->top) {
		ret = SUCCESS;
		StackNode *p = s->top;
		*e = p->data;
	}
	return ret;
}

Status clearLStack(LinkStack *s) {
	Status ret = ERROR;
	s->top = NULL; 
	s->count = 0;
	ret = SUCCESS;
	return ret;
//	StackNode *p = s->top;
//	StackNode *q;
//	while (p != NULL) {
//		q = p;
//		p = p->next;
//		free(q);
//	}
}

Status destroyLStack(LinkStack *s) {
	Status ret = SUCCESS;
	StackNode *p = s->top;
	StackNode *q;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	return ret;
}

Status LStackLength(LinkStack *s,int *length) {
	Status ret = ERROR;
	if (s) {
		ret = SUCCESS;
		*length = s->count;
	}
	return ret;
}

Status pushLStack(LinkStack *s,ElemType data) {
	Status ret = ERROR;
	StackNode *p = (StackNode *)malloc(sizeof(StackNode));
	if (p) {
		ret = SUCCESS;
		p->data = data;
		p->next = s->top;
		s->top = p;
		s->count++;
	}
	return ret;
}

Status popLStack(LinkStack *s,ElemType *data) {
	Status ret = ERROR;
	StackNode *p = s->top;
	if (p) {
		ret = SUCCESS;
		*data = p->data;
		s->top = p->next;
		s->count--;
		free(p);
	}
	return ret;
}

void showPrompt() {
	printf("\t1:��ʼ��ջ\n");
	printf("\t2:�ж�ջ�Ƿ�Ϊ��\n");
	printf("\t3:�õ�ջ��Ԫ��\n");
	printf("\t4:���ջ\n");
	printf("\t5:����ջ\n");
	printf("\t6:���ջ����\n");
	printf("\t7:��ջ\n");
	printf("\t8:��ջ\n");
	printf("\t9:�˳�\n");
}

