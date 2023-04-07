#include "stdio.h"
#include "iostream"
using namespace std;

typedef struct LNode
{
  /* data */
  int data;
  struct LNode *next;
} LNode, *LinkList;
// �ڵ�i��λ�ò���Ԫ��e
bool ListInsert(LinkList &L, int i, int e)
{
  // �ж�i�ĺϷ���
  if (i < 1)
    return false;
  // ��Ҫ�жϲ����λ���Ƿ��ǵ�1��
  if (i == 1)
  {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = L;
    L = s; // ͷָ��ָ���½ڵ�
    return true;
  }
  // i>1��������ͷ���һ����Ψһ������j�ĳ�ʼֵΪ1
  LNode *p;  // ָ��pָ��ǰɨ�赽�Ľ��
  int j = 1; // ��ǰpָ����ǵڼ������
  P = L;
  // ѭ���ҵ���i-1�����
  while (p != NULL && j < i - 1)
  {
    p = p->next;
    j++;
  }
  // pֵΪNULL˵��iֵ���Ϸ�
  if (p == NULL)
    return false;
  // �ڵ�i-1����������½ڵ�
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}