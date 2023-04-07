#include "stdio.h"
#include "iostream"
using namespace std;

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;

// 在结点p后插入元素e
bool InsertNextNode(LNode *p, int e)
{
  if (p == NULL)
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  if (s == NULL)
    return false;
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

// 按位序插入的函数可以直接调用后插操作
bool ListInsert(LinkList &L, int i, int e)
{
  if (i < 1)
    return false;
  LNode *p;
  // 指针p指向当前扫描的结点
  int j = 0;
  // 当前p指向的是第几个结点
  p = L;
  // 循环找到第i-1个结点
  while (p != NULL && j < i - 1)
  {
    // 如果i>length,p最后会等于NULL
    p = p->next;
    j++;
  }
  return InsertNextNode(p, e)
}
