#include "stdio.h"
#include "iostream"
using namespace std;

typedef struct LNode
{
  /* data */
  int data;
  struct LNode *next;
} LNode, *LinkList;
// 在第i个位置插入元素e
bool ListInsert(LinkList &L, int i, int e)
{
  // 判断i的合法性
  if (i < 1)
    return false;
  // 需要判断插入的位置是否是第1个
  if (i == 1)
  {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = L;
    L = s; // 头指针指向新节点
    return true;
  }
  // i>1的情况与带头结点一样，唯一区别是j的初始值为1
  LNode *p;  // 指针p指向当前扫描到的结点
  int j = 1; // 当前p指向的是第几个结点
  P = L;
  // 循环找到第i-1个结点
  while (p != NULL && j < i - 1)
  {
    p = p->next;
    j++;
  }
  // p值为NULL说明i值不合法
  if (p == NULL)
    return false;
  // 在第i-1个结点后插入新节点
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}