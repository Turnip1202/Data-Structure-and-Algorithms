#include "stdio.h"
#include "iostream"
typedef struct LNode
{
  int data;
  struct LNode *next;
} DNode, *LinkList;
// ��ʼ��ѭ��������
bool InitList(LinkList &L)
{
  L = (LNode *)malloc(sizeof(LNode));
  if (L == NULL)
    return false;
  // ���һ������nextָ��ָ��ͷ���
  L->next = L;
  return true;
}

// �ж�ѭ�������Ƿ�Ϊ��
bool Empty(LinkList L)
{
  if (L->next == L)
    return true;
  else
    return false;
}

// �жϽ��p�Ƿ�Ϊѭ��������ı�β���
bool isTail(LinkList L, LNode *p)
{
  if (p->next == L)
    return true;
  else
    return false;
}
