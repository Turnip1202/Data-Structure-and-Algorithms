#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;

// 在结点p前插入元素e
bool InsertPriorNode(LNode *p, int e)
{
  if (p == NULL)
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  // 内存不足分配失败
  if (s == NULL)
    return false;
  // 将s插入结点p之后
  s->next = p->next;
  p->next = s;
  // 交换两个结点中的数据
  s->data = p->data;
  p->data = e;
  return true;
}
