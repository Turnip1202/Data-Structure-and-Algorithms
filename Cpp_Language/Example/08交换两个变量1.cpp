#include "iostream"
using namespace std;
int main()
{
  int a = 5, b = 10, tem;
  cout << "����֮ǰ:" << endl;
  cout << "a = " << a << ", b = " << b << endl;
  // ʹ����ʱ�������洢
  tem = a;
  a = b;
  b = tem;
  cout << endl
       << "����֮��" << endl;
  cout << "a = " << a << ", b = " << b << endl;
  return 0;
}