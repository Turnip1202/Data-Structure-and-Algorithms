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