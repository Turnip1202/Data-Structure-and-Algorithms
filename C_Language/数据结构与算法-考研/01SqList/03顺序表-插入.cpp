#include "stdlib.h"
#include "iostream"
using namespace std;

#define MaxSize 10 // 定义最大长度

typedef struct
{
  int data[MaxSize]; // 用静态的数组存放数据元素
  int length;        // 顺序表的当前长度
} SqList;

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

int main()
{
  SqList L;
  InitList(L);
  ListInsert(L, 3, 3);
  return 0;
}
