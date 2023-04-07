// ��д���ݽṹ֮ջ�ṹ
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include "iostream"
#include "string.h"
using namespace std;
/**
 * ADTջ�ṹ(stack)
 * Data
 *      ͬ���Ա�Ԫ�ؾ�����ͬ�����ͣ�����Ԫ�ؾ���ǰ���ͺ�̹�ϵ
 * Operation
 *    InitStack(*S):��ʼ������������һ����ջ
 *    ClearStack(*S):��ջ���
 *    DestroyStack(*S):��ջ���ڣ�������ջ
 *    StackEmpty(S):��ջΪ�գ�����true�����򷵻�false
 *    GetTop(S,*e):��ջ�����ҷǿգ�����e����ջS��ջ��Ԫ��
 *    Push(*S,e):��ջS���ڣ�������Ԫ��e��ջS�в���Ϊջ��Ԫ��
 *    Pop(*S,*e):ɾ��ջS��ջ��Ԫ�أ�����e������ֵ
 *    StackLength(S):����ջS��Ԫ�ظ���
 * endADT
 */

// ջ�ṹ�Ĵ���ʵ�֣�
#define OK 1    // �ɹ�״̬��
#define ERROR 0 // ʧ��״̬��
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 // ջ�ռ�ĳ�ʼ����

// �����������״̬����
typedef int Status;
typedef int SElemType; // ջ��Ԫ�ص�����

// ����˳��洢��ջ�ṹ
typedef struct
{
  SElemType data[MAXSIZE];
  int top; // ջ��ָ��
} SqStack;

// ����һ����ӡջԪ�صķ���
Status visit(SElemType c)
{
  cout << c << endl;
  return OK;
};

// ��ʼ��ջ������һ����ջ
Status InitStack(SqStack *S)
{
  S->top = -1;
  return OK;
};

// ���ջ
Status ClearStack(SqStack *S)
{
  S->top = -1;
  return OK;
}

// ����ջ
Status DestroyStack(SqStack *S)
{
  ClearStack(S);
  return OK;
};

// ���ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S)
{
  if (S.top == -1)
    return TRUE;
  else
    return FALSE;
}

// ��ջ��Ϊ�գ��򷵻�ջ��Ԫ��
Status GetTop(SqStack S, SElemType *e)
{
  if (S.top == -1)
    return ERROR;
  else
    *e = S.data[S.top];
  return OK;
}

// ��ջ�в�����Ԫ��
Status Push(SqStack *S, SElemType e)
{
  if (S->top == MAXSIZE - 1)
    return ERROR;
  S->data[++S->top] = e;
  return OK;
}

// ɾ��ջS��ջ��Ԫ�أ�����e������ֵ
Status Pop(SqStack *S, SElemType *e)
{
  // �ж�ջ�Ƿ�Ϊ��
  if (S->top == -1)
    return ERROR;
  *e = S->data[S->top--];
  return OK;
}

// ����ջԪ�صĸ�������ջ�ĳ���
Status StackLength(SqStack S)
{
  return S.top + 1;
}
// ��ջ����ջ�����ζ�ջ��ÿ��Ԫ����ʾ
Status StackTraverse(SqStack S)
{
  int i = 0;
  if (S.top == -1)
    return ERROR;
  while (i < S.top)
  {
    visit(S.data[i++]);
  }
  return OK;
}
int main()
{
  SqStack s;
  int e;
  if (InitStack(&s) == OK)
  {
    for (int i = 1; i <= 10; i++)
      Push(&s, i);
  }
  cout << "ջ��Ԫ������Ϊ:" << endl;
  StackTraverse(s);
  Pop(&s, &e);
  cout << "������ջ��Ԫ��e=" << e << endl;
  cout << "ջ�շ�" << StackEmpty(s) << endl;
  GetTop(s, &e);
  cout << "ջ��Ԫ��e" << e << "ջ�ĳ���Ϊ:" << StackLength(s) << endl;
  ClearStack(&s);
  cout << "���ջ��ջ�շ�:" << StackEmpty(s) << endl;
  return 0;
}