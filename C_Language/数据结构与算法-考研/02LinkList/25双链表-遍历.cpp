#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct DNode
{                             // ����˫����������
  int data;                   // ������
  struct DNode *prior, *next; // ǰ���ͺ��ָ��
} DNode, *DLinkList;
int main()
{
  DLinkList L;
  DNode *p = L;
  // ������
  while (p != NULL)
  {
    // �Խ��p����Ӧ����
    p = p->next;
  }

  // ��ǰ����
  while (p != NULL)
    p = p->prior;

  // ����ͷ���ı���
  while (p->prior != NULL)
    p = p->prior;
}
