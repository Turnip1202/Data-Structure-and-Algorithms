#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "iostream"
#include "math.h"
#include "time.h"
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int SElemType; // ����ջ��Ԫ������

// ��ջ�ṹ
// �ڵ�
typedef struct StackNode
{
  SElemType data;
  struct StackNode *next;
} StackNode, *LinkStackPtr;
// ջ
typedef struct
{
  LinkStackPtr top; // ջ��ָ��
  int count;
} LinkStack;

// �鿴Ԫ��
Status visit(SElemType c)
{
  cout << c << " ";
  return OK;
}

// ����һ����ջ
Status InitStack(LinkStack *S)
{
  S->top = (LinkStackPtr)malloc(sizeof(StackNode));
  if (!S->top)
    return ERROR; // �ڴ治��
  S->top = NULL;
  S->count = 0;
  return OK;
}

// ���ջ
Status ClearStack(LinkStack *S)
{
  // ��������ָ�룬p����ѭ��ջ��q����freeջԪ��
  LinkStackPtr p, q;
  p = S->top; // �Ƚ�pָ��ջ��
  while (p)
  {
    q = p;       // ��qָ��ǿյ�ջԪ��p
    p = p->next; // ָ����һ��վԪ��
    free(q);     // �ͷ�ջԪ��
  }
  S->count = 0; // ��ջ��Ԫ����������
  return OK;
}

// �ж�ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S)
{
  if (S.count == 0)
    return TRUE;
  else
    return FALSE;
}

// ����ջ��Ԫ�صĸ���
int StackLength(LinkStack S)
{
  return S.count;
}

// ����ջ��Ԫ��
Status GetTop(LinkStack S, SElemType *e)
{
  if (S.top == NULL)
    return ERROR;
  else
    *e = S.top->data;
  return OK;
}

// ����Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(LinkStack *S, SElemType e)
{
  StackNode *n = (StackNode *)malloc(sizeof(StackNode));
  n->data = e;
  n->next = S->top;
  S->top = n;
  ++S->count;
  return OK;
}

// ��ջ��Ϊ�գ�ɾ��ջ��Ԫ��
Status Pop(LinkStack *S, SElemType *e)
{
  StackNode *p;
  if (StackEmpty(*S))
    return ERROR;
  *e = S->top->data;
  p = S->top;            // ��ջ���ڵ��p
  S->top = S->top->next; // ջ��ָ������
  free(p);               // �ͷŸղŵ�ջ��Ԫ��
  --S->count;
  return OK;
}

Status StackTraverse(LinkStack S)
{
  LinkStackPtr p;
  p = S.top;
  while (p)
  {
    visit(p->data);
    p = p->next;
  }
  return OK;
}
int main()
{
  int i;
  LinkStack s;
  int e;
  if (InitStack(&s) == OK)
    for (i = 1; i <= 10; i++)
      Push(&s, i);
  cout
      << "ջ��Ԫ������Ϊ" << endl;
  StackTraverse(s);
  Pop(&s, &e);
  cout << "\n"
       << "������ջ��Ԫ��e=" << e << endl;
  cout << "ջ�շ�:" << StackEmpty(s) << endl;
  GetTop(s, &e);
  cout << "ջ��Ԫ��e=" << e << "ջ�ĳ���" << StackLength(s) << endl;
  ClearStack(&s);
  cout << "���ջ��ջ�շ�:" << StackEmpty(s);
  return 0;
}