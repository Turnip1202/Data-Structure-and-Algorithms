#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct LNode
{
  /* data */
  int data;
  struct LNode *next;
} LNode, *LinkList;

// ��ʼ��һ��������(��ͷ�ڵ�)
bool InitList(LinkList &L)
{
  L = (LNode *)malloc(sizeof(LNode)); // ����һ��ͷ���
  if (L == NULL)
    return false;
  L->next = NULL; // ͷ���֮����ʱ��û�нڵ�
  return true;
}

void test()
{
  LinkList L; // ����һ��ָ�������ͷָ��
  // ��ʼ��һ���ձ�
  InitList(L);
}
bool Empty(LinkList L)
{
  if (L->next == NULL)
    return true;
  else
    return false;
}

int main()
{
  test();

  cout << "����ִ��1" << endl;
  return 0;
}