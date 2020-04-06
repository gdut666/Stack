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

