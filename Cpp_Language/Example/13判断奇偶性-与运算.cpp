#include "iostream"
using namespace std;
int main()
{
  int n = 1;
  cout << "输入一个整数：";
  cin >> n;
  if ((n & 1) == 0)
    cout << n << "为偶数。";
  else
    cout << n << "为奇数";
  return 0;
}