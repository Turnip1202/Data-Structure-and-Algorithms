#include "stdio.h"
#include "iostream"
using namespace std;
#define MaxSize 100

struct TreeNode
{
  /* data */
  int value;    // 结点中的数据元素
  bool isEmpty; // 结点是否为空
};

// 初始化树
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
  cout << "01程序执行" << endl;
  return 0;
}
