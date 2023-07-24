#include "iostream"
#include "string.h"
using namespace std;
int main()
{
  // 创建变量
  int myNum = 5;              // 整型
  float myFloatNum = 5.99;    // 单精度浮点型
  double myDoubleNum = 9.98;  // 双精度浮点型
  char myLetter = 'D';        // 字符型
  bool myBoolean = true;      // 布尔型
  string myString = "Turnip"; // 字符串

  // 输出变量
  cout << "int:" << myNum << "\n";
  cout << "float:" << myFloatNum << endl;
  cout << "char:" << myLetter << endl;
  cout << "bool:" << myBoolean << endl;
  cout << "string:" << myString << "\n";
  return 0;
}