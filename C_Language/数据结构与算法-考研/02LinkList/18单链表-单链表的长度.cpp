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

// 查找指定位序i的结点并返回
LNode *GetElem(LinkList L, int i)
{
  if (i < 0)
    return NULL;
  LNode *p;
  int j = 0;
  p = L;
  while (p != NULL && j < i)
  {
    /* code */
    p = p->next;
    j++;
  }
  return p;
}

// 封装后的插入操作，在第i个位置插入元素e，可以调用查询操作和后插操作
bool ListInsert(LinkList &L, int i, int e)
{
  if (i < 1)
    return false;
  // 找到第i-1个元素
  LNode *p = GetElem(L, i - 1);
  // 在p结点后插入元素e
  return InsertNextNode(p, e);
}

// 查找数据域为e的结点指针，否则返回NULL
LNode *LocateElem(LinkList L, ElemType e)
{
  LNode *P = L->next;
  // 从第一个结点开始查找数据域为e的结点
  while (p != NULL && p->data != e)
  {
    p = p->next;
  }
  return p;
}

// 计算单链表的长度
int length(LinkList L)
{
  int len = 0; // 统计表长
  LNode *p = L;
  while (p->next != NULL)
  {
    p = p->next;
    len++;
  }
  return len;
}