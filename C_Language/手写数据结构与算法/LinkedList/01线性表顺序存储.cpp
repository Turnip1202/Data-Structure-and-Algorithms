/**
 * ATD ���Ա�(List)
 * Data
 *      ���Ա������Ԫ�ؼ���Ϊ{a1,a2,...,an},ÿ��Ԫ�ص����;�ΪDataType��
 * ���У�����һ��Ԫ��a1�⣬ÿ��Ԫ�����ҽ���һ��ֱ�ӵ�ǰ��Ԫ�أ�
 * �������һ��Ԫ��an�⣬ÿ��Ԫ�����ҽ���һ��ֱ�Ӻ��Ԫ�ء�
 * ����Ԫ��֮��Ĺ�ϵ��һ��һ�Ĺ�ϵ��
 *
 * Operation
 *    InitList(*L): ��ʼ������������һ���յ����Ա�L
 *    ListEmpty(L): �����Ա�Ϊ�գ�����true�����򷵻�false
 *    ClearList(*L):�����Ա����
 *    GetElem(L,i,*e):�����Ա�L�еĵ�i��λ��Ԫ��ֵ���ظ�e
 *    LocateElem(L,e):�����Ա�L�в��������ֵe��ȵ�Ԫ�أ�������ҳɹ���
 *    ���ظ�Ԫ���ڱ�����ű�ʾ�ɹ������򣬷���0��ʾʧ�ܡ�
 *    ListInsert(*L,i,e):�����Ա�L�еĵ�i��λ�ò�����Ԫ��e
 *    ListDeleete(*L,i,*e):ɾ�����Ա�L�е�i��λ��Ԫ�أ�����e������ֵ
 *    ListLength(L):�������Ա�L��Ԫ�ظ���
 */

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include "iostream"
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int ElemType;
typedef struct
{
  ElemType data[MAXSIZE]; // �洢����Ԫ��
  int length;             // ���Ա�ǰ�ĳ���
} SqList;

// ���庯������ֵ������
typedef int Status;

Status visit(ElemType c)
{
  cout << c << " ";
  return OK;
}

// ��ʼ������
Status InitList(SqList *L)
{
  L->length = 0;
  return OK;
}

// �ж����Ա��Ƿ�Ϊ��
// ע����������Ƕ�ȡL�����ԣ����Բ���Ҫʹ��ָ�����L
Status ListEmpty(SqList L)
{
  if (L.length == 0)
    return TRUE;
  else
    return FALSE;
}

// �����Ա����
// ������Ҫֱ�Ӷ�L���в���������Ҫʹ��ָ��
Status ClearList(SqList *L)
{
  L->length = 0;
  return OK;
}

// �����Ա�L�е�i��λ�õ�Ԫ��
Status GetElem(SqList L, int i, ElemType *e)
{
  if (L.length == 0 || i < 1 || i > L.length)
    return ERROR;
  *e = L.data[i - 1];
  return OK;
}

// �����Ա��в��Ҹ�����Ԫ��e,����λ�򼴿�
int LocateElem(SqList L, ElemType e)
{
  // ����һ������i���������ұ�L
  int i;
  // �������Ա���в���
  for (i = 0; i < L.length; ++i)
  {
    if (L.data[i] == e)
      break;
  }
  if (i > L.length)
    return 0;
  return i + 1;
}

// �����Ա�L�еĵ�i��λ�ò�����Ԫ��e
Status ListInsert(SqList *L, int i, ElemType e)
{
  int k;
  // �ж����Ա��Ƿ�����
  if (L->length == MAXSIZE)
    return ERROR;
  // �ж��Ƿ�������λ��
  if (i < 1 || i > L->length + 1)
    return ERROR;
  // �������λ�ò��ڱ�β
  if (i < L->length)
  {
    for (k = L->length + 1; k >= i - 1; --k)
      L->data[k + 1] = L->data[k];
  }
  // �����Ѿ��Ѳ��ڱ�β������ų����ˣ�����λ���ڱ�β
  L->data[i - 1] = e;
  ++L->length;
  return OK;
}

// ɾ��ָ��λ�õ�Ԫ��
Status ListDelete(SqList *L, int i, ElemType *e)
{
  int k;
  if (L->length == 0)
    return ERROR;
  if (i < 1 || i > L->length)
    return ERROR;
  *e = L->data[i - 1];
  if (i < L->length)
    for (k = i; k < L->length; k++)
      L->data[k - 1] = L->data[k];
  --L->length;
  return OK;
}

// ������Ա�
Status ListTraverse(SqList L)
{
  int i;
  for (i = 0; i < L.length; i++)
  {
    visit(L.data[i]);
  }
  cout << endl;
  return OK;
}

int ListLength(SqList L)
{
  return L.length;
}

int unionL(SqList *La, SqList Lb)
{
  int la_len, lb_len, i;
  ElemType e;
  la_len = ListLength(*La);
  lb_len = ListLength(Lb);
  for (i = 1; i <= lb_len; i++)
  {
    GetElem(Lb, i, &e);
    if (!LocateElem(*La, e))
      ListInsert(La, ++la_len, e);
  }
  return OK;
}

int main()
{

  SqList L;
  SqList Lb;

  ElemType e;
  Status i;
  int j, k;
  i = InitList(&L);
  printf("��ʼ��L��L.length=%d\n", L.length);
  for (j = 1; j <= 5; j++)
    i = ListInsert(&L, 1, j);
  printf("��L�ı�ͷ���β���1��5��L.data=");
  ListTraverse(L);

  printf("L.length=%d \n", L.length);
  i = ListEmpty(L);
  printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

  i = ClearList(&L);
  printf("���L��L.length=%d\n", L.length);
  i = ListEmpty(L);
  printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

  for (j = 1; j <= 10; j++)
    ListInsert(&L, j, j);
  printf("��L�ı�β���β���1��10��L.data=");
  ListTraverse(L);

  printf("L.length=%d \n", L.length);

  ListInsert(&L, 1, 0);
  printf("��L�ı�ͷ����0��L.data=");
  ListTraverse(L);
  printf("L.length=%d \n", L.length);

  GetElem(L, 5, &e); // �ڲ�����ȡ����Ԫ�ظ���e
  printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
  for (j = 3; j <= 4; j++)
  {
    k = LocateElem(L, j);
    if (k)
      printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
    else
      printf("û��ֵΪ%d��Ԫ��\n", j);
  }

  k = ListLength(L); /* kΪ�� */
  for (j = k + 1; j >= k; j--)
  {
    i = ListDelete(&L, j, &e); /* ɾ����j������ */
    if (i == ERROR)
      printf("ɾ����%d������ʧ��\n", j);
    else
      printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
  }
  printf("�������L��Ԫ�أ�");
  ListTraverse(L);

  j = 5;
  ListDelete(&L, j, &e); /* ɾ����5������ */
  printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);

  printf("�������L��Ԫ�أ�");
  ListTraverse(L);

  // ����һ����10������Lb
  i = InitList(&Lb);
  for (j = 6; j <= 15; j++)
    i = ListInsert(&Lb, 1, j);

  unionL(&L, Lb);

  printf("��������ϲ���Lb��L��Ԫ�أ�");
  ListTraverse(L);

  return 0;
}
