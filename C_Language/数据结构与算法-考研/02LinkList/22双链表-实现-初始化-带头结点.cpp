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
