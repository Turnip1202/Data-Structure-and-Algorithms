#include "stdio.h"
#include "iostream"
using namespace std;
#define MaxSize 10 // ��̬�������󳤶�
struct Node
{ // ��̬����ṹ�����͵Ķ���
  /* data */
  int data; // �洢����Ԫ��
  int next; // ��һ��Ԫ�ص������±�
};
typedef struct
{           // ��̬����ṹ�����͵Ķ���
  int data; // �洢����Ԫ��
  int next; // ��һ��Ԫ�ص������±�
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