#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;
// 删除指定结点p
bool DeleteNode(LNode *p)
{
  if (p == NULL)
    return false;
  LNode *q = p->next; // 令q指向p的后继结点
  // 如果p是最后一个结点，则q指向NULL，继续执行就会报错
  p->data = q->data;
  p->next = q->next;
  free(q);
  return true;
}