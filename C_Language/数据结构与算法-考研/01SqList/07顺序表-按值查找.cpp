#include "stdio.h"
#include "iostream"
using namespace std;
#define InitSize 10 // ˳���ĳ�ʼ����

// ��̬����İ�λ����
typedef struct
{
  int *data;
  int MaxSize;
  int length;
} SqList;

// ��ʼ��˳���
void InitList(SqList &L)
{
  // ��malloc��������һƬ�����Ĵ洢�ռ�
  L.data = (int *)malloc(InitSize * sizeof(int));
  L.length = 0;
  L.MaxSize = InitSize;
}

// ��˳���iλ�ò���e
bool ListInsert(SqList &L, int i, int e)
{
  if (i < 1 || i > L.length + 1) // �ж�i�ķ�Χ�Ƿ���Ч
    return false;
  if (L.length >= L.MaxSize) // �жϴ洢�ռ��Ƿ�����
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

// ��̬����İ�λ����
int GetElem(SqList L, int i)
{
  return L.data[i - 1];
}

// ���ҵ�һ��Ԫ��ֵΪe��Ԫ�أ���������λ��
int LocateElem(SqList L, int e)
{
  for (int i = 0; i < L.length; i++)
  {
    if (L.data[i] == e)
    {
      return i + 1; // �����±�Ϊi��Ԫ��ֵ����e��������λ��i+1
    }
  }
  return 0; // û�в��ҷ���0
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
  cout << "λ��:" << LocateElem(L, 3) << endl;
}