/**
 * ATD 线性表(List)
 * Data
 *      线性表的数据元素集合为{a1,a2,...,an},每个元素的类型均为DataType。
 * 其中，除第一个元素a1外，每个元素有且仅有一个直接的前驱元素，
 * 除了最后一个元素an外，每个元素有且仅有一个直接后继元素。
 * 数据元素之间的关系是一对一的关系。
 *
 * Operation
 *    InitList(*L): 初始化操作，建立一个空的线性表L
 *    ListEmpty(L): 若线性表为空，返回true，否则返回false
 *    ClearList(*L):将线性表清空
 *    GetElem(L,i,*e):将线性表L中的第i个位置元素值返回给e
 *    LocateElem(L,e):在线性表L中查找与给定值e相等的元素，如果查找成功，
 *    返回该元素在表中序号表示成功，否则，返回0表示失败。
 *    ListInsert(*L,i,e):在线性表L中的第i个位置插入新元素e
 *    ListDeleete(*L,i,*e):删除线性表L中第i个位置元素，并用e返回其值
 *    ListLength(L):返回线性表L的元素个数
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
  ElemType data[MAXSIZE]; // 存储数据元素
  int length;             // 线性表当前的长度
} SqList;

// 定义函数返回值的类型
typedef int Status;

Status visit(ElemType c)
{
  cout << c << " ";
  return OK;
}

// 初始化操作
Status InitList(SqList *L)
{
  L->length = 0;
  return OK;
}

// 判断线性表是否为空
// 注意这里仅仅是读取L的属性，所以不需要使用指针操作L
Status ListEmpty(SqList L)
{
  if (L.length == 0)
    return TRUE;
  else
    return FALSE;
}

// 将线性表清空
// 这里需要直接对L进行操作，所有要使用指针
Status ClearList(SqList *L)
{
  L->length = 0;
  return OK;
}

// 将线性表L中第i个位置的元素
Status GetElem(SqList L, int i, ElemType *e)
{
  if (L.length == 0 || i < 1 || i > L.length)
    return ERROR;
  *e = L.data[i - 1];
  return OK;
}

// 在线性表中查找给定的元素e,返回位序即可
int LocateElem(SqList L, ElemType e)
{
  // 定义一个变量i，用来查找表L
  int i;
  // 遍历线性表进行查找
  for (i = 0; i < L.length; ++i)
  {
    if (L.data[i] == e)
      break;
  }
  if (i > L.length)
    return 0;
  return i + 1;
}

// 在线性表L中的第i个位置插入新元素e
Status ListInsert(SqList *L, int i, ElemType e)
{
  int k;
  // 判断线性表是否已满
  if (L->length == MAXSIZE)
    return ERROR;
  // 判断是否是正常位置
  if (i < 1 || i > L->length + 1)
    return ERROR;
  // 若插入的位置不在表尾
  if (i < L->length)
  {
    for (k = L->length + 1; k >= i - 1; --k)
      L->data[k + 1] = L->data[k];
  }
  // 上述已经把不在表尾的情况排除完了，插入位置在表尾
  L->data[i - 1] = e;
  ++L->length;
  return OK;
}

// 删除指定位置的元素
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

// 输出线性表
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
  printf("初始化L后：L.length=%d\n", L.length);
  for (j = 1; j <= 5; j++)
    i = ListInsert(&L, 1, j);
  printf("在L的表头依次插入1～5后：L.data=");
  ListTraverse(L);

  printf("L.length=%d \n", L.length);
  i = ListEmpty(L);
  printf("L是否空：i=%d(1:是 0:否)\n", i);

  i = ClearList(&L);
  printf("清空L后：L.length=%d\n", L.length);
  i = ListEmpty(L);
  printf("L是否空：i=%d(1:是 0:否)\n", i);

  for (j = 1; j <= 10; j++)
    ListInsert(&L, j, j);
  printf("在L的表尾依次插入1～10后：L.data=");
  ListTraverse(L);

  printf("L.length=%d \n", L.length);

  ListInsert(&L, 1, 0);
  printf("在L的表头插入0后：L.data=");
  ListTraverse(L);
  printf("L.length=%d \n", L.length);

  GetElem(L, 5, &e); // 内部将获取到的元素给了e
  printf("第5个元素的值为：%d\n", e);
  for (j = 3; j <= 4; j++)
  {
    k = LocateElem(L, j);
    if (k)
      printf("第%d个元素的值为%d\n", k, j);
    else
      printf("没有值为%d的元素\n", j);
  }

  k = ListLength(L); /* k为表长 */
  for (j = k + 1; j >= k; j--)
  {
    i = ListDelete(&L, j, &e); /* 删除第j个数据 */
    if (i == ERROR)
      printf("删除第%d个数据失败\n", j);
    else
      printf("删除第%d个的元素值为：%d\n", j, e);
  }
  printf("依次输出L的元素：");
  ListTraverse(L);

  j = 5;
  ListDelete(&L, j, &e); /* 删除第5个数据 */
  printf("删除第%d个的元素值为：%d\n", j, e);

  printf("依次输出L的元素：");
  ListTraverse(L);

  // 构造一个有10个数的Lb
  i = InitList(&Lb);
  for (j = 6; j <= 15; j++)
    i = ListInsert(&Lb, 1, j);

  unionL(&L, Lb);

  printf("依次输出合并了Lb的L的元素：");
  ListTraverse(L);

  return 0;
}
