#include "iostream"
using namespace std;
int main()
{
  char c;
  bool isChar;
  int isLowerCaseVowel, isUpperCaseVowel;
  cout << "������һ����ĸ" << endl;
  cin >> c;
  isChar = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
  if (isChar)
  {
    isLowerCaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    isUpperCaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    if (isLowerCaseVowel || isUpperCaseVowel)
      cout << c << "��Ԫ��";
    else
      cout << c << "�Ǹ���";
  }
  else
    cout << "����Ĳ�����ĸ";
  return 0;
}