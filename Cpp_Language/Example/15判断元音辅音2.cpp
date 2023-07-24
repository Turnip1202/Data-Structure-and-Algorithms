#include "iostream"
#include "ctype.h"
#include "string.h"
using namespace std;
int main()
{
  char world;
  char c[10];
  bool isChar;
  cout << "请输入一个字母" << endl;
  cin.get(c, 10);
  if (strlen(c) > 1)
  {
    cout << "不是字符串";
    return 0;
  }
  world = c[0];
  isChar = ((world >= 'a' && world <= 'z') || (world >= 'A' && world <= 'Z'));
  if (isChar)
  {
    if (world == 'a' || world == 'e' || world == 'i' || world == 'o' || world == 'u' || world == 'A' || world == 'E' || world == 'I' || world == 'O' || world == 'U')
      cout << c << "是元音";

    else
      cout << c << "是辅音";
    return 0;
  }
  cout << "不是字母" << endl;
  return 0;
}