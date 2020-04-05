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

