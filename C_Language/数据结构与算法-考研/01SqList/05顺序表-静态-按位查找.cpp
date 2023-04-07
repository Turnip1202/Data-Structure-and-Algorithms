#include "stdio.h"
#include "iostream"
using namespace std;

// ��̬����İ�λ����
#define MaxSize 10
typedef struct
{
  int data[MaxSize];
  int length;
} SqList;

// ��̬����İ�λ����
int GetElem(SqList L, int i)
{
  return L.data[i - 1];
}
// ��ʼ��˳���
void InitList(SqList &L)
{
  L.length = 0; // ˳��������Ϊ0
}

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

// ɾ��˳���iλ�õ����ݲ�����e
bool ListDelete(SqList &L, int i, int &e)
{
  if (i < 1 || i > L.length) // �ж�i�ķ�Χ�Ƿ���Ч
    return false;
  e = L.data[i - 1];                 // ����ɾ����Ԫ�ظ�ֵ��e
  for (int j = i; j < L.length; j++) // ����i��λ�ú��Ԫ��ǰ��
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
  cout << "Ԫ��:" << GetElem(L, 3) << endl;
}