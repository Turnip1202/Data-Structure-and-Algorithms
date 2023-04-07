#include "stdio.h"
#include "iostream"
using namespace std;

// 使用尾插法建立单链表L
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;
// 使用尾插法建立单链表L
LinkList List_TailInsert(LinkList &L)
{
  int x;                               // 设ElemType为整形int
  L = (LinkList)malloc(sizeof(LNode)); // 建立头结点(初始化空表)
  LNode *s, *r = L;                    // r为表尾指针
  scanf("%d", &x);                     // 输入要插入的结点
  while (x != 9999)
  {
    /* code */
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s; // r指针指向新的表尾结点
    scanf("%d", &x);
  }
  r->next = NULL; // 尾结点的指针置空
  return L;
}

LinkList List_HeadInsert(LinkList &L)
{ // 逆向建立单链表
  LNode *s;
  int x;
  L = (LinkList)malloc(sizeof(LNode)); // 建立头结点
  L->next = NULL;                      // 初始化为空链表，防止野指针
  scanf("%d", &x);                     // 输入要插入的结点的值
  while (x != 999)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = L->next;
    L->next = s;
    // 将新结点插入表中，L为头指针
    scanf("%d", &x);
  }
  return L;
}

// 将链表L中的数据逆置并返回
LNode *Inverse(LNode *L)
{
  LNode *p, *q;
  p = L->next;    // p指针指向第一个结点
  L->next = NULL; // 头结点置空
  // 依次判断p结点中的数据并采用头插法插到L链表中
  while (p != NULL)
  {
    q = p;
    p = p->next;
    q->next = L->next;
    L->next = q;
  }
  return L;
}