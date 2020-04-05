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
	int isInit = 0; //�ж��Ƿ��ʼ�� 
	SqStack *s = NULL;
	
	while(1) {
		showPrompt();
		printf("������Ҫִ�еĲ���: ");
		
        choice = scanf("%d",&temp);
		if (choice == 0) {
			fflush(stdin);
			printf("��������ȷ�����֣�\n");
			continue;
		}
		else choice = temp;
			if(choice<=0||choice>9)
        { 	
            printf("��������ȷ�����֣�\n");continue;
        }
        
		switch(choice) {
			case 1:
				if (isInit == 1) {
					printf("ջ�ѳ�ʼ����\n");
					break;
				}
				s = (SqStack *)malloc(sizeof(SqStack));
				printf("������ջ�Ĵ�С��");
				maxSize = scanf("%d",&temp);
				if (maxSize == 0) {
					fflush(stdin);
					printf("��������ȷ�����ְ���\n");
					continue;
				}
				else maxSize = temp;
				if (initStack(s,maxSize) == SUCCESS) {
					isInit = 1;
					printf("��ʼ���ɹ���\n");
				}
				break;
				
			case 2:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					break;
				}
				if (isEmptyStack(s) == SUCCESS) {
					printf("ջΪ�գ�\n"); 
				}
				else printf("ջ��Ϊ�գ�\n");
				break;
				
			case 3:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					break;
				}
				if (getTopStack(s,&top) == SUCCESS) {
					printf("ջ��Ԫ��Ϊ%d\n",top); 
				}
				else printf("ջΪ�գ�\n");
				break;
				
			case 4:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					break;
				}
				if (clearStack(s) == SUCCESS) {
					printf("ջ��ճɹ���\n");
				}
				break;
				
			case 5:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					break;
				}
				if (destroyStack(s) == SUCCESS) {
					printf("ջ���ٳɹ���\n");
					isInit = 0;
				}
				break;
				
			case 6:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					break;
				}
				if (stackLength(s,&length) == SUCCESS) {
					printf("ջ����Ϊ%d\n",length);
				}
				break;
			
			case 7:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					break;
				}
				printf("������Ҫ��ջ������:");
				data = scanf("%d",&temp);
				if (data == 0) {
					fflush(stdin);
					printf("��������ȷ�����ְ���\n");
					break;
				}
				else data = temp;
				if (pushStack(s,data) == SUCCESS) printf("��ջ�ɹ���\n");
				else printf("��ջʧ�ܣ�\n");
				break;
			
			case 8:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					break;
				}
				if (popStack(s,&pop) == SUCCESS) {
					printf("��ջ�ɹ�������Ϊ%d\n",pop);
				}
				break;
				
			case 9:
				return 0;
		}
	} 
	return 0;
}
