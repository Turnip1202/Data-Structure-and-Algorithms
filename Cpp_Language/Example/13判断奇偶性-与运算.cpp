#include "iostream"
using namespace std;
int main()
{
  int n = 1;
  cout << "����һ��������";
  cin >> n;
  if ((n & 1) == 0)
    cout << n << "Ϊż����";
  else
    cout << n << "Ϊ����";
  return 0;
}