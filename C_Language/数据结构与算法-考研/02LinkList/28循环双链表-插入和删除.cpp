#include "stdio.h"
#include "iostream"
using namespace std;

typedef struct DNode
{
  int data;
  struct DNode *prior, *next;
} DNode, *DLinkList;
// ��ʼ��ѭ��˫����
bool InitDLinkList(DLinkList &L)
{
  L = (DNode *)malloc(sizeof(DNode));
  if (L == NULL)
    return false;
  // ͷ����priorָ��ָ�����һ����㣬���һ������nextָ��ָ��ͷ���
  L->prior = L;
  L->next = L;
}
// �ж�˫ѭ�������Ƿ�Ϊ��
bool Empty(DLinkList L)
{
  if (L->next == L)
    return true;
  else
    return false;
}

// �жϽ��p�Ƿ�Ϊѭ��˫����ı�β���
bool isTail(DLinkList L, DNode *p)
{
  if (p->next == L)
    return true;
  else
    return false;
}

// �����s���뵽���p֮��
bool InsertNextDNode(DNode *p, DNode *s)
{
  s->next = p->next;
  // ѭ��˫�����õ���p������һ���ڵ�Ϊ��
  p->next->prior = s;
  s->prior = p;
  p->next = s;
}
// ɾ��p���ĺ�̽��
bool DeleteNextDNode(DNode *p)
{
  // �ҵ�p�ĺ�̽��q
  DNode *q = p->next;
  // ѭ��˫�����õ���q������һ�����Ϊ��
  p->next = q->next;
  q->next->prior = p;
  free(q);
  return true;
}