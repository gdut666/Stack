//#ifndef STACK_H_INCLUDED
//#define STACK_H_INCLUDED

typedef enum dStatus 
{
    dERROR = 0, 
	dSUCCESS = 1
} dStatus;

typedef double dElemType;

typedef  struct dStackNode
{
	dElemType data;
	struct dStackNode *next;
}dStackNode, *dLinkStackPtr;

typedef  struct  dLinkStack
{
	dLinkStackPtr dtop;
	int	dcount;
}dLinkStack;



//��ջ
dStatus dinitLStack(dLinkStack *s);//��ʼ��ջ
dStatus disEmptyLStack(dLinkStack *s);//�ж�ջ�Ƿ�Ϊ��
dStatus dgetTopLStack(dLinkStack *s,dElemType *e);//�õ�ջ��Ԫ��
dStatus dclearLStack(dLinkStack *s);//���ջ
dStatus ddestroyLStack(dLinkStack *s);//����ջ
dStatus dLStackLength(dLinkStack *s,int *length);//���ջ����
dStatus dpushLStack(dLinkStack *s,dElemType data);//��ջ
dStatus dpopLStack(dLinkStack *s,dElemType *data);//��ջ
void dshowPrompt();

//#endif 
