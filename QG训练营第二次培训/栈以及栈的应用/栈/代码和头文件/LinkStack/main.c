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
        
        switch (choice) {
			case 1:
				if (isInit == 1) {
					printf("ջ�ѳ�ʼ����\n");
					continue;
				}
				s = (LinkStack *)malloc(sizeof(LinkStack));
				isInit = 1;
				if (initLStack(s) == SUCCESS) printf("��ʼ���ɹ���\n");
				else printf("��ʼ��ʧ�ܣ�\n");
				break;
				
			case 2:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					continue;
				}
				if (isEmptyLStack(s) == SUCCESS) printf("ջΪ�գ�\n");
				else printf("ջ��Ϊ�գ�\n");
				break;
				
			case 3:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					continue;
				}
				if (getTopLStack(s,&e) == SUCCESS) {
					printf("ջ��Ԫ��Ϊ%d\n",e);
				}
				else printf ("ջΪ�գ�\n");
				break;
				
			case 4:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					continue;
				}
				if (isEmptyLStack(s) == SUCCESS) {
					printf("ջ��Ϊ�գ�������գ�\n");
					continue;
				}
				if (clearLStack(s) == SUCCESS) printf("ջ��ճɹ���\n");
				else printf("ջ���ʧ�ܣ�\n");
				break;
				
			case 5:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					continue;
				}
				if (destroyLStack(s) == SUCCESS) {
					printf("ջ���ٳɹ���\n");
					isInit = 0;
				}
				else printf("ջ����ʧ�ܣ�\n");
				break;
				
			case 6:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					continue;
				}
				if (LStackLength(s,&length) == SUCCESS) printf("���ջ����Ϊ%d\n",length);
				else printf("�޷����ջ���ȣ�\n");
				break;
			
			case 7:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					continue;
				}
				printf("������Ҫ��ջ������:");
				data = scanf("%d",&temp);
				if (data == 0) {
					fflush(stdin);
					printf("��������ȷ�����֣�\n");
					break;
				}
				else data = temp;
				if (pushLStack(s,data) == SUCCESS) {
					printf("��ջ�ɹ���\n");
				}
				else printf("��ջʧ�ܣ�\n");
				break;
				
			case 8:
				if (isInit == 0) {
					printf("ջδ��ʼ����\n");
					continue;
				}
				if (popLStack(s,&e) == SUCCESS) printf("��ջ�ɹ�����ջ����Ϊ%d\n",e);
				else printf("ջΪ�գ�\n");
				break;
				
			case 9:
				return 0;
		}
	}
}
