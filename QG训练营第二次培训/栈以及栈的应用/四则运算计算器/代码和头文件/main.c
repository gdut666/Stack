//利用栈实现简易计算器,进行包含+,-,*,/,(,)间的计算 
#include<stdio.h>
#include<string.h>
#include "LinkStack.h"
#include "dLinkStack.h"
#define MaxSize 100000 
 


 
int Isop(char );				//当前扫描元素优先级 
int Inop(char );				//栈顶元素优先级 
 
void Trans(char*s1,char*s2);		        //转化为后缀表达式 
 
double Calculate(char *s2);			//后缀表达式求值 
 
 
 
 
 
int main()
{
	printf("                 没有对输入做太多出错处理，请师兄手下留情！\n");
	printf("                  输入例子:6*(4-3)+2=\n\n");
	char s1[MaxSize];			//用于存储前缀表达式 
	char s2[MaxSize];			//用于存储转换后的表达式 
	char y;
	while(1) {
		printf("请输入表达式:");
		scanf("%s",s1);
		
		Trans(s1,s2);				//处理字符串，并转化为后缀表达式,存放在s2中 
		
		printf("计算结果为: %f",Calculate(s2));		//后缀表达式求值 
		printf("\n输入y以继续:\n"); 
		fflush(stdin);
		scanf("%c",&y);
		if (y == 'y'||y == 'Y')
		continue;
		else return 0;
		}
}
 

int Isop(char op)		//当前扫描运算符优先级
{
	switch(op)
	{
		case '(': return 6;
		case '+': case '-': return 2;
		case '*': case '/': return 4;
	}
}
int Inop(char op)		//当前扫描运算符优先级
{
	switch(op)
	{
		case '(': return 1;
		case '+': case '-': return 3;
		case '*': case '/': return 5;
	}
}
 
void Trans(char *s1,char *s2)
{
	char top;
	char temp;
	int i=0;
	int j=0;
	int flag1=-1;				//flag1为0表示上次输出为数字，flag1为1表示上次输出为字符
	int flag2=-1; 				//flag2为0表示上次扫描为数字，flag为1表示上次扫描为运算符，用于区分数字后加空格
	LinkStack st1;				//暂放运算符 
	initLStack(&st1);
	
	while(s1[i]!='\0')			//处理负数 
	{
		if(s1[0]=='-')			//第一位数字为负数时 
		{
			j=strlen(s1);
			while(j>0)
			{
				s1[j+5]=s1[j];
				j--;
			}
			s1[j++]='(';
			s1[j++]='0';
			s1[j++]='-';
			s1[j++]='1';
			s1[j++]=')';
			s1[j]='*';
			
		}
		if(s1[i]=='('&&s1[i+1]=='-')	
		{
			j=strlen(s1);
			while(j>i+1)
			{
				s1[j+5]=s1[j];
				j--;
			}
			s1[j++]='(';
			s1[j++]='0';
			s1[j++]='-';
			s1[j++]='1';
			s1[j++]=')';
			s1[j]='*';
			i=i+5;
		}
		i++;
	}
	
	i=0;
	j=0;
	while(s1[i]!='\0')
	{
		if(flag1==0&&flag2==1)		 
		{
			s2[j++]=' ';
			flag1=1; 
		}
		if(s1[i]>='0'&&s1[i]<='9'||s1[i]=='.')
		{
			s2[j++]=s1[i];
			flag2=0;
			flag1=0;
		}
		else if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='(')
		{
			flag2=1;
			if(getTopLStack(&st1,&top),st1.top == NULL||Isop(s1[i])>Inop(top))
			{
				pushLStack(&st1,s1[i]);
			}
			else
			{
				while( getTopLStack(&st1,&top),st1.top!=NULL&&Isop(s1[i])<Inop(top) )		 
				{
						popLStack(&st1,&s2[j++]);
						flag1=1;
				}
				if(getTopLStack(&st1,&top),st1.top==NULL||Isop(s1[i])>Inop(top))			 
				{
					pushLStack(&st1,s1[i]);
				}
				
			}
		}
		else if(s1[i]==')')				 
		{
			flag2=1;
			if(getTopLStack(&st1,&top),top!='(')		 
			{
				flag1=1;
			}
			while(getTopLStack(&st1,&top),top!='(')
			{
				popLStack(&st1,&s2[j++]);
			}
			popLStack(&st1,&temp);		
		}
		i++;
	}
	while(st1.top != NULL)		 
	{
		popLStack(&st1,&s2[j++]);
	}
	s2[j]='\0';
}
 
 
double Calculate(char *s1)
{
	double temp;
	int i=0;
	int flag;			
	double data1,data2;
	double sum;
	dLinkStack ds1;
	
	dinitLStack(&ds1);
	while(s1[i]!='\0')
	{
		if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/')		
		{
			dpopLStack(&ds1,&data1);
			dpopLStack(&ds1,&data2);
			if(s1[i]=='+') dpushLStack(&ds1,data2+data1);
			else if(s1[i]=='-') dpushLStack(&ds1,data2-data1);
			else if(s1[i]=='*') dpushLStack(&ds1,data2*data1);
			else if(s1[i]=='/') dpushLStack(&ds1,data2/data1);
		}
		else						
		{
			flag=0;				 
			sum=0;
			double divider=1;
			while(s1[i]!=' '&&s1[i]!='+'&&s1[i]!='-'&&s1[i]!='*'&&s1[i]!='/')
			{
				if(s1[i]=='.')		
				{
					flag=1;
					i++;
					continue;
				}
				if(flag==0)
				{
					sum=sum*10+(double)(s1[i]-'0');
				}
				else
				{
					divider=divider*10;
					sum=sum+((double)(s1[i]-'0'))/divider;
				}
				i++;
			}
			if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/') i--;	
			dpushLStack(&ds1,sum);
		}
		i++;		
	}
	 return dpopLStack(&ds1,&temp),temp;
}
