#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;
// 删除第i个结点并将其所保存的数据存入e
bool ListDelete(LinkList &L, int i, int &e)
{
  if (i < 1)
    return false;
  LNode *p;  // 指针p指向当前扫描到的结点
  int j = 0; // 当前p指向的是第几个结点
  p = L;
  // 循环找到第i-1个结点
  while (p != NULL && j < i - 1)
  {
    // 如果i>length，p和p的后继结点会等于NULL
    p = p->next;
    j++;
  }
  if (p == NULL)
    return false;
  if (p->next == NULL)
    return false;
  // 令q暂时保存被删除的结点
  LNode *q = p->next;
  e = q->data;
  p->next = q->next;
  free(q);
  return true;
}