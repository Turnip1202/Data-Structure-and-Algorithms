#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;
// ɾ����i����㲢��������������ݴ���e
bool ListDelete(LinkList &L, int i, int &e)
{
  if (i < 1)
    return false;
  LNode *p;  // ָ��pָ��ǰɨ�赽�Ľ��
  int j = 0; // ��ǰpָ����ǵڼ������
  p = L;
  // ѭ���ҵ���i-1�����
  while (p != NULL && j < i - 1)
  {
    // ���i>length��p��p�ĺ�̽������NULL
    p = p->next;
    j++;
  }
  if (p == NULL)
    return false;
  if (p->next == NULL)
    return false;
  // ��q��ʱ���汻ɾ���Ľ��
  LNode *q = p->next;
  e = q->data;
  p->next = q->next;
  free(q);
  return true;
}