#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct DNode
{                             // ����˫����������
  int data;                   // ������
  struct DNode *prior, *next; // ǰ���ͺ��ָ��
} DNode, *DLinkList;
// ��ʼ��˫����
bool InitDLinkList(DLinkList &L)
{
  L = (DNode *)malloc(sizeof(DNode));
  if (L == NULL)
    return false;
  L->prior = NULL; // ͷ����priorָ����Զָ��NULL
  L->next = NULL;  // ͷ���֮����ʱ��û�н�㣬�ÿ�
  return true;
}
void testDLinkList()
{
  DLinkList L;
  InitDLinkList(L);
}
// �ж�˫�����Ƿ�Ϊ��
bool Empty(DLinkList L)
{
  if (L->next == NULL)
    return true;
  else
    return false;
}

// �����s���뵽���p֮��
bool InsertNextDNode(DNode *p, DNode *s)
{
  if (p == NULL || s == NULL)
    return false;
  s->next = p->next;
  // �жϽ��p֮���Ƿ��к�̽��
  if (p->next != NULL)
    p->next->prior = s;
  s->prior = p;
  p->next = s;
  return true;
}

// ɾ��p���ĺ�̽��
bool DeleteNextDNode(DNode *p)
{
  if (p == NULL)
    return false;
  // �ҵ�p�ĺ�̽��q
  DNode *q = p->next;
  if (q == NULL)
    return false;
  p->next = q->next;
  if (q->next != NULL)
    q->next->prior = p;
  free(q);
  return true;
}

// ����һ��˫����
bool DestoryList(DLinkList &L)
{
  // ѭ���ͷŸ������ݽ��
  while (L->next != NULL)
  {
    DeleteNextDNode(L);
    free(L);
    // ͷָ���ÿ�
    L = NULL;
  }
}
