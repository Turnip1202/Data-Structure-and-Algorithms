#include "stdio.h"
#include "iostream"
using namespace std;
#define InitSize 10 // 顺序表的初始长度

// 静态分配的按位查找
typedef struct
{
  int *data;
  int MaxSize;
  int length;
} SqList;

// 初始化顺序表
void InitList(SqList &L)
{
  // 用malloc函数申请一片连续的存储空间
  L.data = (int *)malloc(InitSize * sizeof(int));
  L.length = 0;
  L.MaxSize = InitSize;
}

// 在顺序表i位置插入e
bool ListInsert(SqList &L, int i, int e)
{
  if (i < 1 || i > L.length + 1) // 判断i的范围是否有效
    return false;
  if (L.length >= L.MaxSize) // 判断存储空间是否已满
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

// 动态分配的按位查找
int GetElem(SqList L, int i)
{
  return L.data[i - 1];
}

// 查找第一个元素值为e的元素，并返回其位序
int LocateElem(SqList L, int e)
{
  for (int i = 0; i < L.length; i++)
  {
    if (L.data[i] == e)
    {
      return i + 1; // 数组下标为i的元素值等于e，返回其位序i+1
    }
  }
  return 0; // 没有查找返回0
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
  cout << "位序:" << LocateElem(L, 3) << endl;
}