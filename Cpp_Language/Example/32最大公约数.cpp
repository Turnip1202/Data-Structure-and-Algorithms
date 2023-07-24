#include "iostream"
using namespace std;
int main()
{
  int n1, n2, min;
  cout << "请输入两个整数:";
  cin >> n1 >> n2;
  min = n1 * n2;
  while (n1 != n2)
  {
    if (n1 > n2)
      n1 -= n2;
    else
      n2 -= n1;
  }
  cout << "最大公约数是:" << n1 << endl;
  cout << "最小公倍数是:" << min / n1;

  return 0;
}