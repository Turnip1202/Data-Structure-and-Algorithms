#include "stdio.h"
#include "iostream"
using namespace std;

typedef struct DNode
{
  int data;
  struct DNode *prior, *next;
} DNode, *DLinkList;
// 初始化循环双链表
bool InitDLinkList(DLinkList &L)
{
  L = (DNode *)malloc(sizeof(DNode));
  if (L == NULL)
    return false;
  // 头结点的prior指针指向最后一个结点，最后一个结点的next指针指向头结点
  L->prior = L;
  L->next = L;
}
// 判断双循环链表是否为空
bool Empty(DLinkList L)
{
  if (L->next == L)
    return true;
  else
    return false;
}

// 判断结点p是否为循环双链表的表尾结点
bool isTail(DLinkList L, DNode *p)
{
  if (p->next == L)
    return true;
  else
    return false;
}