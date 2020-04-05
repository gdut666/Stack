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
	if (s->top == -1) printf("栈为空！无需清理！\n");
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
	if (s->top == (s->size)-1) printf("栈已满\n");
	else {
		ret = SUCCESS;
		(s->top)++;
		*((s->elem) + (s->top)) = data;
	}
	return ret;
}

Status popStack(SqStack *s,ElemType *data) {
	Status ret = ERROR;
	if (s->top == -1) printf("栈为空\n");
	else {
		ret = SUCCESS;
		(*data) = *(s->elem + s->top);
		(s->top)--;
	}
	return ret;
}

void showPrompt() {
	printf("\t1:初始化栈\n");
	printf("\t2:判断栈是否为空\n");
	printf("\t3:得到栈顶元素\n");
	printf("\t4:清空栈\n");
	printf("\t5:销毁栈\n");
	printf("\t6:检测栈长度\n");
	printf("\t7:入栈\n");
	printf("\t8:出栈\n");
	printf("\t9:退出\n");
}

 
