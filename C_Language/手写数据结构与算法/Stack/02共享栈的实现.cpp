#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include "string.h"
#include "iostream"
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 // ջ��ʼ����ռ�
typedef int Status;
typedef int SElemType; // �ٶ���ջԪ������

// ����ջ�Ľṹ
typedef struct
{
  SElemType data[MAXSIZE];
  int top1; // ջ1��ջ��ָ��
  int top2; // ջ2��ջ��ָ��
} SqDoubleStack;

Status visit(SElemType c)
{
  cout << c << " ";
  return OK;
}

// ��ʼ��һ����ջ
Status InitStack(SqDoubleStack *S)
{
  S->top1 = -1;
  S->top2 = MAXSIZE;
  return OK;
}

// ���ջ
Status ClearStack(SqDoubleStack *S)
{
  S->top1 = -1;
  S->top2 = MAXSIZE;
  return OK;
}

// �ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqDoubleStack S)
{
  if (S.top1 == -1 && S.top2 == MAXSIZE)
    return TRUE;
  else
    return FALSE;
}
// ����ջ��Ԫ��
int StackLength(SqDoubleStack S)
{
  return (S.top1 + 1) + (MAXSIZE - S.top2);
}

// ����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
  if (S->top1 + 1 == S->top2) // ��ջ
    return ERROR;
  if (stackNumber == 1)     // ջ1 ��Ԫ�ؽ�ջ
    S->data[++S->top1] = e; // ջ1���Ƚ�top1+1���ٽ�Ԫ�ؽ�ջ
  if (stackNumber == 2)     // ջ2 ��Ԫ�ؽ�ջ
    S->data[--S->top2] = e; // ջ2�� �Ƚ�top2-1���ٽ�Ԫ�ؽ�ջ
  return OK;
}

Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
  if (stackNumber == 1)
  {
    if (S->top1 == -1)
      return ERROR; //
    *e = S->data[S->top1--];
  }
  if (stackNumber == 2)
  {
    if (S->top2 == MAXSIZE)
      return ERROR;
    *e = S->data[S->top2++];
  }
  return OK;
}

// ��ӡջ
Status StackTraverse(SqDoubleStack S)
{
  int i = 0;
  while (i <= S.top1)
    visit(S.data[i++]);
  i = S.top2;
  while (i < MAXSIZE)
    visit(S.data[i++]);
  return OK;
}
int main()
{
  int i = 1;
  SqDoubleStack s;
  int e;
  if (InitStack(&s) == OK)
  {
    for (i = 1; i <= 5; i++)
      Push(&s, i, 1); // ��ʼ����һ��ջ
    for (i = MAXSIZE; i >= MAXSIZE - 2; i--)
      Push(&s, i, 2); // ��ʼ���ڶ���ջ
  }
  cout << "ջ��Ԫ������Ϊ��" << endl;
  StackTraverse(s);
  cout << "��ǰջ��Ԫ����:" << StackLength(s) << endl;
  Pop(&s, &e, 2); // ����ջ2��ջ��Ԫ��
  cout << "������ջ��Ԫ��e=" << e << endl;
  cout << "ջ�շ�:" << StackEmpty(s) << endl;

  for (i = 6; i < MAXSIZE - 2; i++)
    Push(&s, i, 1);
  cout << "ջ�е�Ԫ������Ϊ:";
  StackTraverse(s);
  cout << "\n"
       << "ջ����:" << Push(&s, 100, 1) << endl;
  ClearStack(&s);
  cout << "���ջ��ջ�շ�:" << StackEmpty(s) << endl;
  return 0;
}