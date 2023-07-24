#include "iostream"
using namespace std;
int main()
{
  char c;
  bool isChar;
  int isLowerCaseVowel, isUpperCaseVowel;
  cout << "请输入一个字母" << endl;
  cin >> c;
  isChar = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
  if (isChar)
  {
    isLowerCaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    isUpperCaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    if (isLowerCaseVowel || isUpperCaseVowel)
      cout << c << "是元音";
    else
      cout << c << "是辅音";
  }
  else
    cout << "输入的不是字母";
  return 0;
}