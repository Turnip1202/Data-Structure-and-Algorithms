#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;

// �ڽ��pǰ����Ԫ��e
bool InsertPriorNode(LNode *p, int e)
{
  if (p == NULL)
    return false;
  LNode *s = (LNode *)malloc(sizeof(LNode));
  // �ڴ治�����ʧ��
  if (s == NULL)
    return false;
  // ��s������p֮��
  s->next = p->next;
  p->next = s;
  // ������������е�����
  s->data = p->data;
  p->data = e;
  return true;
}
