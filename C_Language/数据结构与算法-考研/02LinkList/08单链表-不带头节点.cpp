#include "stdio.h"
#include "iostream"
using namespace std;
// ���嵥����
typedef struct LNode
{
  /* data */
  int data;
  struct LNode *next;
} LNode, *LinkList;
// �ṹ�����������Ժͽṹ��������ظ�
//  ��ʼ��һ���յĵ�����
bool InitList(LinkList &L)
{
  L = NULL; // �ձ���ʱ��û���κνڵ�
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
  return (L == NULL);
}
int main()
{
  test();
  cout << "��������" << endl;
  return 0;
}