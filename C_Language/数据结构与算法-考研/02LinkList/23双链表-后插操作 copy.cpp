#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct DNode
{                             // 定义双链表结点类型
  int data;                   // 数据域
  struct DNode *prior, *next; // 前驱和后继指针
} DNode, *DLinkList;
// 初始化双链表
bool InitDLinkList(DLinkList &L)
{
  L = (DNode *)malloc(sizeof(DNode));
  if (L == NULL)
    return false;
  L->prior = NULL; // 头结点的prior指针永远指向NULL
  L->next = NULL;  // 头结点之后暂时还没有结点，置空
  return true;
}
void testDLinkList()
{
  DLinkList L;
  InitDLinkList(L);
}
// 判断双链表是否为空
bool Empty(DLinkList L)
{
  if (L->next == NULL)
    return true;
  else
    return false;
}

// 将结点s插入到结点p之后
bool InsertNextDNode(DNode *p, DNode *s)
{
  if (p == NULL || s == NULL)
    return false;
  s->next = p->next;
  // 判断结点p之后是否有后继结点
  if (p->next != NULL)
    p->next->prior = s;
  s->prior = p;
  p->next = s;
  return true;
}
