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
#define MAXSIZE 20 // 栈初始分配空间
typedef int Status;
typedef int SElemType; // 假定的栈元素类型

// 共享栈的结构
typedef struct
{
  SElemType data[MAXSIZE];
  int top1; // 栈1的栈顶指针
  int top2; // 栈2的栈顶指针
} SqDoubleStack;

Status visit(SElemType c)
{
  cout << c << " ";
  return OK;
}

// 初始化一个空栈
Status InitStack(SqDoubleStack *S)
{
  S->top1 = -1;
  S->top2 = MAXSIZE;
  return OK;
}

// 清空栈
Status ClearStack(SqDoubleStack *S)
{
  S->top1 = -1;
  S->top2 = MAXSIZE;
  return OK;
}

// 判断栈是否为空
Status StackEmpty(SqDoubleStack S)
{
  if (S.top1 == -1 && S.top2 == MAXSIZE)
    return TRUE;
  else
    return FALSE;
}
// 返回栈内元素
int StackLength(SqDoubleStack S)
{
  return (S.top1 + 1) + (MAXSIZE - S.top2);
}

// 插入元素e为新的栈顶元素
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
  if (S->top1 + 1 == S->top2) // 满栈
    return ERROR;
  if (stackNumber == 1)     // 栈1 有元素进栈
    S->data[++S->top1] = e; // 栈1，先将top1+1，再将元素进栈
  if (stackNumber == 2)     // 栈2 有元素进栈
    S->data[--S->top2] = e; // 栈2， 先将top2-1，再将元素进栈
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

// 打印栈
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
      Push(&s, i, 1); // 初始化第一个栈
    for (i = MAXSIZE; i >= MAXSIZE - 2; i--)
      Push(&s, i, 2); // 初始化第二个栈
  }
  cout << "栈中元素依次为：" << endl;
  StackTraverse(s);
  cout << "当前栈中元素有:" << StackLength(s) << endl;
  Pop(&s, &e, 2); // 弹出栈2的栈顶元素
  cout << "弹出的栈顶元素e=" << e << endl;
  cout << "栈空否:" << StackEmpty(s) << endl;

  for (i = 6; i < MAXSIZE - 2; i++)
    Push(&s, i, 1);
  cout << "栈中的元素依次为:";
  StackTraverse(s);
  cout << "\n"
       << "栈满否:" << Push(&s, 100, 1) << endl;
  ClearStack(&s);
  cout << "清空栈后，栈空否:" << StackEmpty(s) << endl;
  return 0;
}