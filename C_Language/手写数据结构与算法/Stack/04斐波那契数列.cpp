#include "stdio.h"

// 斐波那契数列的递归函数
int Fbi(int i)
{
  if (i < 2)
    return i == 0 ? 0 : 1;
  return Fbi(i - 1) + Fbi(i - 2);
}

int main()
{
  int i;
  int a[40];
  a[0] = 0;
  a[1] = 1;
  printf("%d\n", a[0]);
  printf("%d\n", a[1]);
  printf("迭代显示斐波那契数列:\n");

  for (i = 2; i < 40; i++)
  {
    a[i] = a[i - 1] + a[i - 2];
    printf(" %d ", a[i]);
  }
  printf("\n");

  printf("递归显示斐波那契数列:\n");
  for (i = 0; i < 40; i++)
    printf("%d ", Fbi(i));
  return 0;
}