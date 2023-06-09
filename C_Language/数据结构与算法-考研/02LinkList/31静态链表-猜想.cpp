#include "stdio.h"
#include "iostream"
using namespace std;
#define MaxSize 10 // 静态链表的最大长度
struct Node
{ // 静态链表结构体类型的定义
  /* data */
  int data; // 存储数据元素
  int next; // 下一个元素的数组下标
};
typedef struct
{           // 静态链表结构体类型的定义
  int data; // 存储数据元素
  int next; // 下一个元素的数组下标
} SLinkList[MaxSize];

void testSLinkList()
{
  struct Node x;
  printf("sizeX=%d\n", sizeof(x));
  struct Node a[MaxSize];
  printf("sizeA=%d\n", sizeof(a));
  SLinkList b;
  printf("sizeB=%d\n", sizeof(b));
}
int main()
{
  testSLinkList();
  return 0;
}