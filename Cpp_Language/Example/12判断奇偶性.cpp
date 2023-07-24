#include "iostream"
using namespace std;
// int main()
// {
//   int n;
//   cout << "输入一个整数:";
//   cin >> n;
//   if (n % 2 == 0)
//     cout << n << "为偶数" << endl;
//   else
//     cout << n << "为奇数" << endl;
//   return 0;
// }
int main()
{
  int n;
  cout << "输入一个整数:" << endl;
  cin >> n;
  (n % 2 == 0) ? cout << n << "为偶数" : cout << n << "为奇数";
  return 0;
}