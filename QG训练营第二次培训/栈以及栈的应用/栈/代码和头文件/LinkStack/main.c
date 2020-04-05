#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int data;
	int e;
	int isInit = 0;
	int choice;
	int temp;
	int length;
	LinkStack *s;
	
	while (1) {
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
        
        switch (choice) {
			case 1:
				if (isInit == 1) {
					printf("栈已初始化！\n");
					continue;
				}
				s = (LinkStack *)malloc(sizeof(LinkStack));
				isInit = 1;
				if (initLStack(s) == SUCCESS) printf("初始化成功！\n");
				else printf("初始化失败！\n");
				break;
				
			case 2:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					continue;
				}
				if (isEmptyLStack(s) == SUCCESS) printf("栈为空！\n");
				else printf("栈不为空！\n");
				break;
				
			case 3:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					continue;
				}
				if (getTopLStack(s,&e) == SUCCESS) {
					printf("栈顶元素为%d\n",e);
				}
				else printf ("栈为空！\n");
				break;
				
			case 4:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					continue;
				}
				if (isEmptyLStack(s) == SUCCESS) {
					printf("栈已为空！无需清空！\n");
					continue;
				}
				if (clearLStack(s) == SUCCESS) printf("栈清空成功！\n");
				else printf("栈清空失败！\n");
				break;
				
			case 5:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					continue;
				}
				if (destroyLStack(s) == SUCCESS) {
					printf("栈销毁成功！\n");
					isInit = 0;
				}
				else printf("栈销毁失败！\n");
				break;
				
			case 6:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					continue;
				}
				if (LStackLength(s,&length) == SUCCESS) printf("检测栈长度为%d\n",length);
				else printf("无法检测栈长度！\n");
				break;
			
			case 7:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					continue;
				}
				printf("请输入要入栈的数据:");
				data = scanf("%d",&temp);
				if (data == 0) {
					fflush(stdin);
					printf("请输入正确的数字！\n");
					break;
				}
				else data = temp;
				if (pushLStack(s,data) == SUCCESS) {
					printf("入栈成功！\n");
				}
				else printf("入栈失败！\n");
				break;
				
			case 8:
				if (isInit == 0) {
					printf("栈未初始化！\n");
					continue;
				}
				if (popLStack(s,&e) == SUCCESS) printf("出栈成功！出栈数据为%d\n",e);
				else printf("栈为空！\n");
				break;
				
			case 9:
				return 0;
		}
	}
}
