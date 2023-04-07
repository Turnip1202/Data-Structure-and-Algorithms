#include "stdio.h"
#include "iostream"
using namespace std;
// 定义单链表
typedef struct LNode
{
  /* data */
  int data;
  struct LNode *next;
} LNode, *LinkList;
// 结构体类型名可以和结构体变量名重复
//  初始化一个空的单链表
bool InitList(LinkList &L)
{
  L = NULL; // 空表，暂时还没有任何节点
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
  return (L == NULL);
}
int main()
{
  test();
  cout << "程序运行" << endl;
  return 0;
}