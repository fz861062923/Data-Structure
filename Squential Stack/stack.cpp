#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 8 //栈的最大容量 
typedef int SElemType;//定义栈的元素类型
typedef int Status;
const int ERROR = 0;
const int OK = 1;
const int TRUE = 1;
const int FALSE = 0;
const int LIST_SIZE = 100;
//顺序栈的数据结构
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
 }sqStack;

//初始化顺序表
Status InitStack(sqStack &S)
{
	S.base=new SElemType[MAXSIZE];
	if(!S.base)
		return ERROR;
	//栈顶指针初始为base表示为栈空
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK; 
 } 
//入栈
Status Push(sqStack &S,SElemType e)
{
	if(S.top-S.base==MAXSIZE)
		return ERROR;
	*S.top++=e;
	return OK;
 } 
//出栈
Status Pop(sqStack &S,SElemType &e)
{
	if(S.top==S.base)
		return ERROR;
	e=*--S.top;
	return OK;
 } 
//取出栈顶元素
Status GetTop(sqStack S)
{
	if(S.top!=S.base)
		return OK;
}

int main()
{
    sqStack S;            //创建栈S
    InitStack(S);            //初始化栈 
    int e;                //入栈与出栈的元素

    while(true)
    {
        printf("请选择对顺序栈的操作：\n");
        printf("1->入栈\n");
        printf("2->出栈\n");
        printf("3->取栈顶元素\n");
        printf("4->退出\n");
        printf("********************************");
        int a;
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                printf("请输入入栈的元素：");
                scanf("%d", &e);
                if(Push(S, e))
                    printf("入栈成功\n");
                else
                    printf("入栈失败\n");
                break;
            case 2:
                if(Pop(S, e))
                    printf("出栈的元素为: %d\n",e);//注意记得把出栈元素输出
                else
                    printf("栈空\n");
                break;
            case 3:
            	if(GetTop(S))
            		printf("栈顶元素为: %d\n",*(S.top-1));//注意S.top-1将会输出的是地址 
            	else
					printf("栈空\n");
            case 4:
                break;
            default:
                printf("输入不合法\n");
                break;
        }
    }
}
 
 
 
