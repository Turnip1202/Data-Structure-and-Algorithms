#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct LNode
{
  /* data */
  int data;
  struct LNode *next;
} LNode, *LinkList;

// 初始化一个单链表(带头节点)
bool InitList(LinkList &L)
{
  L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
  if (L == NULL)
    return false;
  L->next = NULL; // 头结点之后暂时还没有节点
  return true;
}

void test()
{
  LinkList L; // 声明一个指向单链表的头指针
  // 初始化一个空表
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

  cout << "程序执行1" << endl;
  return 0;
}