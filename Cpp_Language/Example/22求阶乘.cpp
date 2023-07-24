#include "iostream"
using namespace std;
int main()
{
  unsigned int n;
  unsigned long long factorial = 1;
  cout << "请输入一个整数:";
  cin >> n;
  for (int i = 1; i <= n; ++i)
    factorial *= i;
  cout << n << "的阶乘为:"
       << " " << factorial << endl;

  return 0;
}