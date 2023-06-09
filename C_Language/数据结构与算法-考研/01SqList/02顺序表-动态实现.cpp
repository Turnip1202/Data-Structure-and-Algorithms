#include "stdlib.h"
#include "stdio.h"
#include "iostream"
using namespace std;
#define InitSize 10 // 顺序表的初始长度

typedef struct
{
  int *data;   // 声明动态分配数组的指针
  int MaxSize; // 顺序表的最大容量
  int length;  // 顺序表的当前长度
} SqList;

// 初始化顺序表
void InitList(SqList &L)
{
  // 用malloc函数申请一片连续的存储空间
  L.data = (int *)malloc(InitSize * sizeof(int));
  L.length = 0;
  L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SqList &L, int len)
{
  int *p = L.data;
  L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
  for (int i = 0; i < L.length; i++)
    L.data[i] = p[i];          // 将数据复制到新区域
  L.MaxSize = L.MaxSize + len; // 顺序表最大长度增加len
  free(p);                     // 释放原来的内存空间
}

int main()
{
  SqList L;    // 声明一个顺序表
  InitList(L); // 初始化顺序表
  return 0;
}
