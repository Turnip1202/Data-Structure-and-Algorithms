#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;
// ɾ��ָ�����p
bool DeleteNode(LNode *p)
{
  if (p == NULL)
    return false;
  LNode *q = p->next; // ��qָ��p�ĺ�̽��
  // ���p�����һ����㣬��qָ��NULL������ִ�оͻᱨ��
  p->data = q->data;
  p->next = q->next;
  free(q);
  return true;
}