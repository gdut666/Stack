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



//链栈
dStatus dinitLStack(dLinkStack *s);//初始化栈
dStatus disEmptyLStack(dLinkStack *s);//判断栈是否为空
dStatus dgetTopLStack(dLinkStack *s,dElemType *e);//得到栈顶元素
dStatus dclearLStack(dLinkStack *s);//清空栈
dStatus ddestroyLStack(dLinkStack *s);//销毁栈
dStatus dLStackLength(dLinkStack *s,int *length);//检测栈长度
dStatus dpushLStack(dLinkStack *s,dElemType data);//入栈
dStatus dpopLStack(dLinkStack *s,dElemType *data);//出栈
void dshowPrompt();

//#endif 
