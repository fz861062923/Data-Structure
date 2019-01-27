#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 8 //ջ��������� 
typedef int SElemType;//����ջ��Ԫ������
typedef int Status;
const int ERROR = 0;
const int OK = 1;
const int TRUE = 1;
const int FALSE = 0;
const int LIST_SIZE = 100;
//˳��ջ�����ݽṹ
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
 }sqStack;

//��ʼ��˳���
Status InitStack(sqStack &S)
{
	S.base=new SElemType[MAXSIZE];
	if(!S.base)
		return ERROR;
	//ջ��ָ���ʼΪbase��ʾΪջ��
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK; 
 } 
//��ջ
Status Push(sqStack &S,SElemType e)
{
	if(S.top-S.base==MAXSIZE)
		return ERROR;
	*S.top++=e;
	return OK;
 } 
//��ջ
Status Pop(sqStack &S,SElemType &e)
{
	if(S.top==S.base)
		return ERROR;
	e=*--S.top;
	return OK;
 } 
//ȡ��ջ��Ԫ��
Status GetTop(sqStack S)
{
	if(S.top!=S.base)
		return OK;
}

int main()
{
    sqStack S;            //����ջS
    InitStack(S);            //��ʼ��ջ 
    int e;                //��ջ���ջ��Ԫ��

    while(true)
    {
        printf("��ѡ���˳��ջ�Ĳ�����\n");
        printf("1->��ջ\n");
        printf("2->��ջ\n");
        printf("3->ȡջ��Ԫ��\n");
        printf("4->�˳�\n");
        printf("********************************");
        int a;
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                printf("��������ջ��Ԫ�أ�");
                scanf("%d", &e);
                if(Push(S, e))
                    printf("��ջ�ɹ�\n");
                else
                    printf("��ջʧ��\n");
                break;
            case 2:
                if(Pop(S, e))
                    printf("��ջ��Ԫ��Ϊ: %d\n",e);//ע��ǵðѳ�ջԪ�����
                else
                    printf("ջ��\n");
                break;
            case 3:
            	if(GetTop(S))
            		printf("ջ��Ԫ��Ϊ: %d\n",*(S.top-1));//ע��S.top-1����������ǵ�ַ 
            	else
					printf("ջ��\n");
            case 4:
                break;
            default:
                printf("���벻�Ϸ�\n");
                break;
        }
    }
}
 
 
 
