#include "iostream"
using namespace std;
int main()
{
  int a = 5, b = 10, tem;
  cout << "交换之前:" << endl;
  cout << "a = " << a << ", b = " << b << endl;
  // 使用临时变量来存储
  tem = a;
  a = b;
  b = tem;
  cout << endl
       << "交换之后" << endl;
  cout << "a = " << a << ", b = " << b << endl;
  return 0;
}