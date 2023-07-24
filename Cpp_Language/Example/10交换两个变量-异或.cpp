#include "iostream"
using namespace std;
int main()
{
  int a = 9, b = 4;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  // 两个被交换数异或会得到一个中间值，
  // 两个被交换数中的任意一个和中间值异或就会得到另一个被交换数。
  a = a ^ b; // 得到一个异或的值
  b = a ^ b; // 异或的值 与 原值进行异或
  a = a ^ b;
  cout << "a:" << a << endl;
  cout << "b:" << b << endl;
  return 0;
}