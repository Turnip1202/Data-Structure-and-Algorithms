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

// ��λ�����ĺ�������ֱ�ӵ��ú�����
bool ListInsert(LinkList &L, int i, int e)
{
  if (i < 1)
    return false;
  LNode *p;
  // ָ��pָ��ǰɨ��Ľ��
  int j = 0;
  // ��ǰpָ����ǵڼ������
  p = L;
  // ѭ���ҵ���i-1�����
  while (p != NULL && j < i - 1)
  {
    // ���i>length,p�������NULL
    p = p->next;
    j++;
  }
  return InsertNextNode(p, e)
}
