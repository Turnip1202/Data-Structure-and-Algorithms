#include "stdio.h"
#include "iostream"
using namespace std;

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;
// �ڵ�i��λ�ò���Ԫ��e
bool ListInsert(LinkList &L, int i, int e)
{
  if (i < 1)
    return false;
  LNode *p;  // ָ��pָ��ǰɨ�赽�Ľ��
  int j = 0; // ��ǰpָ����ǵڼ������
  P = L;     // ѭ���ҵ���i-1�����
  while (p != NULL && j < i - 1)
  {
    p = p->next;
    j++;
  }
  // pֵΪNULL˵��iֵ���Ϸ�
  if (p == NULL)
    return false;
  // �ڵ�i-1����������½��
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s; // �����s���ӵ�p��
  return true;
}
