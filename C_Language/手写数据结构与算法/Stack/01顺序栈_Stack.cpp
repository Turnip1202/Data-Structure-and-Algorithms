// 手写数据结构之栈结构
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include "iostream"
#include "string.h"
using namespace std;
/**
 * ADT栈结构(stack)
 * Data
 *      同线性表，元素具有相同的类型，相邻元素具有前驱和后继关系
 * Operation
 *    InitStack(*S):初始化操作，建立一个空栈
 *    ClearStack(*S):将栈清空
 *    DestroyStack(*S):若栈存在，则销毁栈
 *    StackEmpty(S):若栈为空，返回true，否则返回false
 *    GetTop(S,*e):若栈存在且非空，则用e返回栈S的栈顶元素
 *    Push(*S,e):若栈S存在，插入新元素e到栈S中并成为栈顶元素
 *    Pop(*S,*e):删除栈S中栈顶元素，并用e返回其值
 *    StackLength(S):返回栈S的元素个数
 * endADT
 */

// 栈结构的代码实现：
#define OK 1    // 成功状态码
#define ERROR 0 // 失败状态码
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 // 栈空间的初始容量

// 定义各方法的状态类型
typedef int Status;
typedef int SElemType; // 栈内元素的类型

// 定义顺序存储的栈结构
typedef struct
{
  SElemType data[MAXSIZE];
  int top; // 栈顶指针
} SqStack;

// 定义一个打印栈元素的方法
Status visit(SElemType c)
{
  cout << c << endl;
  return OK;
};

// 初始化栈，构造一个空栈
Status InitStack(SqStack *S)
{
  S->top = -1;
  return OK;
};

// 清空栈
Status ClearStack(SqStack *S)
{
  S->top = -1;
  return OK;
}

// 销毁栈
Status DestroyStack(SqStack *S)
{
  ClearStack(S);
  return OK;
};

// 检测栈是否为空
Status StackEmpty(SqStack S)
{
  if (S.top == -1)
    return TRUE;
  else
    return FALSE;
}

// 若栈不为空，则返回栈顶元素
Status GetTop(SqStack S, SElemType *e)
{
  if (S.top == -1)
    return ERROR;
  else
    *e = S.data[S.top];
  return OK;
}

// 向栈中插入新元素
Status Push(SqStack *S, SElemType e)
{
  if (S->top == MAXSIZE - 1)
    return ERROR;
  S->data[++S->top] = e;
  return OK;
}

// 删除栈S中栈顶元素，并用e返回其值
Status Pop(SqStack *S, SElemType *e)
{
  // 判断栈是否为空
  if (S->top == -1)
    return ERROR;
  *e = S->data[S->top--];
  return OK;
}

// 返回栈元素的个数，即栈的长度
Status StackLength(SqStack S)
{
  return S.top + 1;
}
// 从栈底至栈顶依次对栈中每个元素显示
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
  cout << "栈中元素依次为:" << endl;
  StackTraverse(s);
  Pop(&s, &e);
  cout << "弹出的栈顶元素e=" << e << endl;
  cout << "栈空否：" << StackEmpty(s) << endl;
  GetTop(s, &e);
  cout << "栈顶元素e" << e << "栈的长度为:" << StackLength(s) << endl;
  ClearStack(&s);
  cout << "清空栈后，栈空否:" << StackEmpty(s) << endl;
  return 0;
}