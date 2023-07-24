#include "iostream"
using namespace std;
int main()
{
  int Sum(void);
  int n, sum = 0;
  cout << "输入一个正整数:";
  cin >> n;
  for (int i = 1; i <= n; ++i)
    sum += i;
  cout << "sum = " << sum;
  sum = Sum();
  cout << "sum = " << sum;
  return 0;
}

int Sum(void)
{
  int n, sum = 0;
  cin >> n;
  return ((sum + n) * (n + 1)) / 2;
}