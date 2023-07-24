#include "iostream"
#include "stdlib.h"
using namespace std;
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;

void Sort(LinkList &L)
{
  LNode *p = L->next, *pre;
  LNode *r = p->next;
  p->next = NULL; // 构造只包含一个数据节点的有序表
  p = r;
  while (p != NULL)
  {
    r = p->next;
    pre = L;
    while (pre->next != NULL && pre->next->data < p->data)
      pre = pre->next;
    p->next = pre->next;
    pre->next = p;
    p = r;
  }
}
int main()
{
}

void MergeList(LinkList &La, LinkList &Lb)
{
  LNode *r, *pa = La->next, *pb = Lb->next;
  La->next = NULL;
  while (pa && pb)
  {
    if (pa->data <= pb->data)
    {
      r = pa->next;
      pa->next = La->next;
      La->next = pa;
      pa = r;
    }
    else
    {
      r = pb->next;
      pb->next = La->next;
      La->next = pb;
      pb = r;
    }
    if (pa)
      pb = pa;
    while (pb)
    {
      r = pb->next;
      pb->next = La->next;
      La->next = pb;
      pb = r;
    }
    free(Lb);
  }
}