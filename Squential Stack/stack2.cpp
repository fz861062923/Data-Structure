#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define  TRUE  1
#define  FALSE 0
#define  OK    1
#define  ERROR 0
#define  INFEASIBLE -1
#define  OVERFLOW   -2
#define  STACK_INIT_SIZE  100
#define  STACKINCREMENT    10
typedef  int  ElemType;
typedef  int    Status;

//ջ��˳��ṹ��ʾ 
typedef struct
{
    ElemType *base;
    ElemType  *top;
    int  stacksize;
}SqStack;

//1.����һ����ջ 
Status InitStack(SqStack &S)
{
    S.base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if (!S.base)
        exit(OVERFLOW);//�洢����ʧ��
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

//2.����ջ 
Status DestroyStack(SqStack &S)
{
    S.top = NULL; 
    S.stacksize = 0; 
    free(S.base); 
    return OK;
}

//3.���ջ 
Status ClearStack(SqStack &S)
{
    S.top = S.base;
    return OK;
}

//4.�ж�ջ�Ƿ�Ϊ�� 
Status StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return ERROR;
    else
        return TRUE;
}

//5.��ջ�ĳ��� 
Status StackLength(SqStack S)
{
    if (S.top == S.base)
        return FALSE;
    else
        return (S.top - S.base);//Ҳ����ֱ�ӷ���S.top - S.base
}

//6.//��ջ��Ԫ�� 
Status GetTop(SqStack S, ElemType &e)
{
    if (S.top == S.base)
        return FALSE;
    else
        e = *(S.top - 1);
    return e;
}

//7.ջ������Ԫ�� 
Status Push(SqStack &S, ElemType &e)
{
    if (S.top - S.base >= STACK_INIT_SIZE)
    {
        S.base = (ElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S.base)
        {
            return false;
        }
        S.top = S.base + STACK_INIT_SIZE;//ջ�׵�ַ���ܸı䣬���¶�λջ��Ԫ��
        S.stacksize = S.stacksize + STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    return OK;
}

//8.ɾ��ջ��Ԫ�� 
Status Pop(SqStack &S, ElemType &e)
{
    if (S.top == S.base)
        return ERROR;
    else
    {
        S.top--;
        e = *S.top;//˵�����˴�����ʹ���Ի�ʵ���ϴ�Ԫ�ز�û����ɾ��������S.top�У������������Ԫ�أ��ͻᱻ���£�������ɾ����һ��
        return e;
    }
}

//9.����ջ 
Status StackTraverse(SqStack S)
{
    if (S.base == NULL)
        return ERROR;
    if (S.top == S.base)
        printf("ջ��û��Ԫ�ء���\n");
    ElemType *p;
    p = S.top;
    while (p > S.base)
    {
        p--;
        printf("%d ",*p);
    }

    return OK;
}

//������������ֲ��� 
int main()
{
    SqStack S;
    printf("����һ����ջ����\n");
    InitStack(S);
    int i,n ;
    printf("����ջ�ĳ���:\n");
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        printf("����ջ�ĵ�%d��Ԫ��\n",i);
        ++S.top;
        scanf("%d",S.top-1);
    }
    printf("������ջ�ǿ�ջ�𣿡���\n");
    if (StackEmpty(S) == 1)
         printf("����\n");
    else
         printf("�ǵ�\n");
    printf("�������ջ�ĳ��ȡ���\n");
    int m;
    m=StackLength(S);
    printf("ջ�ĳ�����:\n");
    printf("%d\n",m);
    printf("�������ջ�е�����Ԫ��:\n");
    StackTraverse(S);
    printf("\n");
    printf("�������ջ��Ԫ�ء���\n");
    int e;
    e=GetTop(S, e);
    printf("ջ��Ԫ����:\n");
    printf("%d\n",e);
    printf("����ջ������Ԫ�ء���\n");
    printf("������Ҫ�����Ԫ�ص���ֵ:\n");
    scanf("%d",&e);
    Push(S,e);
    printf("����ջ�е�Ԫ����:\n");
    StackTraverse(S);
    printf("\n");
    printf("����ջ��ɾ��Ԫ�ء���\n");
    e=Pop(S,e);
    printf("��ɾ����Ԫ����:\n");
    scanf("%d",&e);
    printf("����ջ�е�Ԫ����:\n");
    StackTraverse(S);
    printf("\n");
    printf("�������ջ����\n");
    ClearStack(S);
    printf("����ջ�е�Ԫ����:\n");
    StackTraverse(S);
    printf("��������ջ����\n");
    if(DestroyStack(S)==1)
        printf("����ջ�ɹ�\n");
    else
        printf("����ջʧ��\n");
    return 0;
}
