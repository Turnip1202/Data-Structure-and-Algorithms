#include "stdio.h"
#include "iostream"
using namespace std;

// ʹ��β�巨����������L
typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode, *LinkList;
// ʹ��β�巨����������L
LinkList List_TailInsert(LinkList &L)
{
  int x;                               // ��ElemTypeΪ����int
  L = (LinkList)malloc(sizeof(LNode)); // ����ͷ���(��ʼ���ձ�)
  LNode *s, *r = L;                    // rΪ��βָ��
  scanf("%d", &x);                     // ����Ҫ����Ľ��
  while (x != 9999)
  {
    /* code */
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s; // rָ��ָ���µı�β���
    scanf("%d", &x);
  }
  r->next = NULL; // β����ָ���ÿ�
  return L;
}