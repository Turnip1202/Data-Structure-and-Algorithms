#include "iostream"
using namespace std;
// int main()
// {
//   int n;
//   cout << "����һ������:";
//   cin >> n;
//   if (n % 2 == 0)
//     cout << n << "Ϊż��" << endl;
//   else
//     cout << n << "Ϊ����" << endl;
//   return 0;
// }
int main()
{
  int n;
  cout << "����һ������:" << endl;
  cin >> n;
  (n % 2 == 0) ? cout << n << "Ϊż��" : cout << n << "Ϊ����";
  return 0;
}