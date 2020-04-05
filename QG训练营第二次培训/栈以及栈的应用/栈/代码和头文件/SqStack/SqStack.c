#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

Status initStack(SqStack *s,int sizes) {
	Status ret = ERROR;
//	int a[sizes];
	if (s) {
		ret = SUCCESS;
		s->elem = (int *)malloc(sizes*sizeof(int));
		s->top = -1;
		s->size = sizes;
	}
	return ret;
} 

Status isEmptyStack(SqStack *s) {
	Status ret = ERROR;
	if (s->top == -1) ret = SUCCESS;
	return ret;
}

Status getTopStack(SqStack *s,ElemType *e) {
	Status ret = ERROR;
	if (s->top != -1) {
		ret = SUCCESS;
		*e = *(s->elem + s->top);
	}
	return ret;
}

Status clearStack(SqStack *s) {
	Status ret = ERROR;
	if (s->top == -1) printf("ջΪ�գ���������\n");
	else {
		ret = SUCCESS;
		s->top = -1;
	} 
	return ret;
}

Status destroyStack(SqStack *s) {
	Status ret = ERROR;
	free(s);
	ret = SUCCESS;
	return ret;
}

Status stackLength(SqStack *s,int *length) {
	Status ret = ERROR;
	if (s) {
		ret = SUCCESS;
		*length = s->top+1;
	}
	return ret;
}

Status pushStack(SqStack *s,ElemType data) {
	Status ret = ERROR;
	if (s->top == (s->size)-1) printf("ջ����\n");
	else {
		ret = SUCCESS;
		(s->top)++;
		*((s->elem) + (s->top)) = data;
	}
	return ret;
}

Status popStack(SqStack *s,ElemType *data) {
	Status ret = ERROR;
	if (s->top == -1) printf("ջΪ��\n");
	else {
		ret = SUCCESS;
		(*data) = *(s->elem + s->top);
		(s->top)--;
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

 
