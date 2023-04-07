#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct DNode
{                             // 定义双链表结点类型
  int data;                   // 数据域
  struct DNode *prior, *next; // 前驱和后继指针
} DNode, *DLinkList;
int main()
{
  DLinkList L;
  DNode *p = L;
  // 向后遍历
  while (p != NULL)
  {
    // 对结点p做相应处理
    p = p->next;
  }

  // 先前遍历
  while (p != NULL)
    p = p->prior;

  // 跳过头结点的遍历
  while (p->prior != NULL)
    p = p->prior;
}
