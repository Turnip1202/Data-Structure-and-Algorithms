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
typedef int SElemType; // 定义栈的元素类型

// 链栈结构
// 节点
typedef struct StackNode
{
  SElemType data;
  struct StackNode *next;
} StackNode, *LinkStackPtr;
// 栈
typedef struct
{
  LinkStackPtr top; // 栈顶指针
  int count;
} LinkStack;

// 查看元素
Status visit(SElemType c)
{
  cout << c << " ";
  return OK;
}

// 构造一个空栈
Status InitStack(LinkStack *S)
{
  S->top = (LinkStackPtr)malloc(sizeof(StackNode));
  if (!S->top)
    return ERROR; // 内存不足
  S->top = NULL;
  S->count = 0;
  return OK;
}

// 清空栈
Status ClearStack(LinkStack *S)
{
  // 定义两个指针，p用来循环栈，q用来free栈元素
  LinkStackPtr p, q;
  p = S->top; // 先将p指向栈顶
  while (p)
  {
    q = p;       // 让q指向非空的栈元素p
    p = p->next; // 指向下一个站元素
    free(q);     // 释放栈元素
  }
  S->count = 0; // 将栈内元素数量清零
  return OK;
}

// 判断栈是否为空
Status StackEmpty(LinkStack S)
{
  if (S.count == 0)
    return TRUE;
  else
    return FALSE;
}

// 返回栈内元素的个数
int StackLength(LinkStack S)
{
  return S.count;
}

// 返回栈顶元素
Status GetTop(LinkStack S, SElemType *e)
{
  if (S.top == NULL)
    return ERROR;
  else
    *e = S.top->data;
  return OK;
}

// 插入元素e为新的栈顶元素
Status Push(LinkStack *S, SElemType e)
{
  StackNode *n = (StackNode *)malloc(sizeof(StackNode));
  n->data = e;
  n->next = S->top;
  S->top = n;
  ++S->count;
  return OK;
}

// 若栈不为空，删除栈顶元素
Status Pop(LinkStack *S, SElemType *e)
{
  StackNode *p;
  if (StackEmpty(*S))
    return ERROR;
  *e = S->top->data;
  p = S->top;            // 将栈顶节点给p
  S->top = S->top->next; // 栈顶指针下移
  free(p);               // 释放刚才的栈顶元素
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
      << "栈中元素依次为" << endl;
  StackTraverse(s);
  Pop(&s, &e);
  cout << "\n"
       << "弹出的栈顶元素e=" << e << endl;
  cout << "栈空否:" << StackEmpty(s) << endl;
  GetTop(s, &e);
  cout << "栈顶元素e=" << e << "栈的长度" << StackLength(s) << endl;
  ClearStack(&s);
  cout << "清空栈后，栈空否:" << StackEmpty(s);
  return 0;
}