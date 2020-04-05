#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	printf("                            SqSTACK\n\n\n"); 
	int top;
	int temp;
	int length;
	int choice;
	int data;
	int pop = -1;
	int maxSize;
	int isInit = 0; //判断是否初始化 
	SqStack *s = NULL;
	
	while(1) {
		showPrompt();
		printf("请输入要执行的操作: ");
		
        choice = scanf("%d",&temp);
		if (choice == 0) {
			fflush(stdin);
			printf("请输入正确的数字！\n");
			continue;
		}
		else choice = temp;
			if(choice<=0||choice>9)
        { 	
            printf("请输入正确的数字！\n");continue;
        }
        
		switch(choice) {
			case 1:
				if (isInit == 1) {
					printf("栈已初始化！\n");
					break;
				}
				s = (SqStack *)malloc(sizeof(SqStack));
				printf("请输入栈的大小：");
				maxSize = scanf("%d",&temp);
				if (maxSize == 0) {
					fflush(stdin);
					printf("请输入正确的数字啊！\n");
					continue;
				}
				else maxSize = temp;
				if (initStack(s,maxSize) == SUCCESS) {
					isInit = 1;
					printf("初始化成功！\n");
				}
				break;
				
			case 2:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					break;
				}
				if (isEmptyStack(s) == SUCCESS) {
					printf("栈为空！\n"); 
				}
				else printf("栈不为空！\n");
				break;
				
			case 3:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					break;
				}
				if (getTopStack(s,&top) == SUCCESS) {
					printf("栈顶元素为%d\n",top); 
				}
				else printf("栈为空！\n");
				break;
				
			case 4:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					break;
				}
				if (clearStack(s) == SUCCESS) {
					printf("栈清空成功！\n");
				}
				break;
				
			case 5:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					break;
				}
				if (destroyStack(s) == SUCCESS) {
					printf("栈销毁成功！\n");
					isInit = 0;
				}
				break;
				
			case 6:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					break;
				}
				if (stackLength(s,&length) == SUCCESS) {
					printf("栈长度为%d\n",length);
				}
				break;
			
			case 7:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					break;
				}
				printf("请输入要入栈的数据:");
				data = scanf("%d",&temp);
				if (data == 0) {
					fflush(stdin);
					printf("请输入正确的数字啊！\n");
					break;
				}
				else data = temp;
				if (pushStack(s,data) == SUCCESS) printf("入栈成功！\n");
				else printf("入栈失败！\n");
				break;
			
			case 8:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					break;
				}
				if (popStack(s,&pop) == SUCCESS) {
					printf("出栈成功！数据为%d\n",pop);
				}
				break;
				
			case 9:
				return 0;
		}
	} 
	return 0;
}
