#include "iostream"
using namespace std;
int main()
{
  int firstNumber, secondNumber, sumOfTowNumbers;
  cout << "请输入两个整数:" << endl;
  cin >> firstNumber >> secondNumber;
  // 相加
  sumOfTowNumbers = firstNumber + secondNumber;
  // 输出
  cout << firstNumber << "+" << secondNumber << "=" << sumOfTowNumbers;

  return 0;
}