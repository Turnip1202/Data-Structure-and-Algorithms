#include "stdio.h"
#include "iostream"
using namespace std;
#define MaxSize 100

struct TreeNode
{
  /* data */
  int value;    // ����е�����Ԫ��
  bool isEmpty; // ����Ƿ�Ϊ��
};

// ��ʼ����
bool initTree(TreeNode T[])
{
  for (int i = 0; i < MaxSize; i++)
    T[i].isEmpty = true;
  return true;
}
void test()
{
  struct TreeNode T[MaxSize];
  initTree(T);
}
int main()
{
  test();
  cout << "01����ִ��" << endl;
  return 0;
}
