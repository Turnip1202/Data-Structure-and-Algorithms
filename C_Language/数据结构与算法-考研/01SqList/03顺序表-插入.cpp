#include "stdlib.h"
#include "iostream"
using namespace std;

#define MaxSize 10 // ������󳤶�

typedef struct
{
  int data[MaxSize]; // �þ�̬������������Ԫ��
  int length;        // ˳���ĵ�ǰ����
} SqList;

// ��˳���iλ�ò���e
bool ListInsert(SqList &L, int i, int e)
{
  if (i < 1 || i > L.length + 1) // �ж�i�ķ�Χ�Ƿ���Ч
    return false;
  if (L.length >= MaxSize) // �жϴ洢�ռ��Ƿ�����
    return false;
  for (int j = L.length; j >= i; j--) // ����i��Ԫ��֮���Ԫ�غ���
    L.data[j] = L.data[j - 1];
  L.data[i - 1] = e; // ��λ��i������e
  L.length++;        // ����+1
  return true;
}

int main()
{
  SqList L;
  InitList(L);
  ListInsert(L, 3, 3);
  return 0;
}
