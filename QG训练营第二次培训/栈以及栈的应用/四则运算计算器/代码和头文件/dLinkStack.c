#include <stdio.h>
#include <stdlib.h>
#include "dLinkStack.h"

dStatus dinitLStack(dLinkStack *s) {
	dStatus ret = dERROR;
	if (s) {
		ret = dSUCCESS;
		s->dtop = NULL;
		s->dcount = 0;
	}
	return ret;
}

dStatus disEmptyLStack(dLinkStack *s) {
	dStatus ret = dERROR;
	if (s->dtop == NULL) ret = dSUCCESS;
	return ret;
}

dStatus dgetdtopLStack(dLinkStack *s,dElemType *e) {
	dStatus ret = dERROR;
	if (s->dtop) {
		ret = dSUCCESS;
		dStackNode *p = s->dtop;
		*e = p->data;
	}
	return ret;
}

dStatus dclearLStack(dLinkStack *s) {
	dStatus ret = dERROR;
	s->dtop = NULL; 
	s->dcount = 0;
	ret = dSUCCESS;
	return ret;
//	dStackNode *p = s->dtop;
//	dStackNode *q;
//	while (p != NULL) {
//		q = p;
//		p = p->next;
//		free(q);
//	}
}

dStatus ddestroyLStack(dLinkStack *s) {
	dStatus ret = dSUCCESS;
	dStackNode *p = s->dtop;
	dStackNode *q;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	return ret;
}

dStatus dLStackLength(dLinkStack *s,int *length) {
	dStatus ret = dERROR;
	if (s) {
		ret = dSUCCESS;
		*length = s->dcount;
	}
	return ret;
}

dStatus dpushLStack(dLinkStack *s,dElemType data) {
	dStatus ret = dERROR;
	dStackNode *p = (dStackNode *)malloc(sizeof(dStackNode));
	if (p) {
		ret = dSUCCESS;
		p->data = data;
		p->next = s->dtop;
		s->dtop = p;
		s->dcount++;
	}
	return ret;
}

dStatus dpopLStack(dLinkStack *s,dElemType *data) {
	dStatus ret = dERROR;
	dStackNode *p = s->dtop;
	if (p) {
		ret = dSUCCESS;
		*data = p->data;
		s->dtop = p->next;
		s->dcount--;
		free(p);
	}
	return ret;
}

void dshowPrompt() {
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

