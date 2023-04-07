#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;
// �ڽ��p�����Ԫ��e
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

// ����ָ��λ��i�Ľ�㲢����
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

// ��װ��Ĳ���������ڵ�i��λ�ò���Ԫ��e�����Ե��ò�ѯ�����ͺ�����
bool ListInsert(LinkList &L, int i, int e)
{
  if (i < 1)
    return false;
  // �ҵ���i-1��Ԫ��
  LNode *p = GetElem(L, i - 1);
  // ��p�������Ԫ��e
  return InsertNextNode(p, e);
}