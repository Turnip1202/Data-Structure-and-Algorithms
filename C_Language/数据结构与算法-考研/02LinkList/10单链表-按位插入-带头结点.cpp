#include "stdio.h"
#include "iostream"
using namespace std;

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;
// 在第i个位置插入元素e
bool ListInsert(LinkList &L, int i, int e)
{
  if (i < 1)
    return false;
  LNode *p;  // 指针p指向当前扫描到的结点
  int j = 0; // 当前p指向的是第几个结点
  P = L;     // 循环找到第i-1个结点
  while (p != NULL && j < i - 1)
  {
    p = p->next;
    j++;
  }
  // p值为NULL说明i值不合法
  if (p == NULL)
    return false;
  // 在第i-1个结点后插入新结点
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s; // 将结点s连接到p后
  return true;
}
