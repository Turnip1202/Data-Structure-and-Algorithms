#include "stdio.h"
#include "iostream"
using namespace std;

// 静态分配的按位查找
#define MaxSize 10
typedef struct
{
  int data[MaxSize];
  int length;
} SqList;

// 静态分配的按位查找
int GetElem(SqList L, int i)
{
  return L.data[i - 1];
}
// 初始化顺序表
void InitList(SqList &L)
{
  L.length = 0; // 顺序表初长度为0
}

// 在顺序表i位置插入e
bool ListInsert(SqList &L, int i, int e)
{
  if (i < 1 || i > L.length + 1) // 判断i的范围是否有效
    return false;
  if (L.length >= MaxSize) // 判断存储空间是否已满
    return false;
  for (int j = L.length; j >= i; j--) // 将第i个元素之后的元素后移
    L.data[j] = L.data[j - 1];
  L.data[i - 1] = e; // 在位置i处放入e
  L.length++;        // 长度+1
  return true;
}

// 删除顺序表i位置的数据并存入e
bool ListDelete(SqList &L, int i, int &e)
{
  if (i < 1 || i > L.length) // 判断i的范围是否有效
    return false;
  e = L.data[i - 1];                 // 将被删除的元素赋值给e
  for (int j = i; j < L.length; j++) // 将第i个位置后的元素前移
    L.data[j - 1] = L.data[j];
  L.length--;
  return true;
}

int main()
{
  SqList L;
  InitList(L);
  int e = -1;
  ListInsert(L, 1, 1);
  ListInsert(L, 2, 2);
  ListInsert(L, 3, 3);
  ListInsert(L, 4, 4);
  ListInsert(L, 5, 5);
  cout << "元素:" << GetElem(L, 3) << endl;
}