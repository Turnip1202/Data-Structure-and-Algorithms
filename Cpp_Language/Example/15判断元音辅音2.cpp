#include "iostream"
#include "ctype.h"
#include "string.h"
using namespace std;
int main()
{
  char world;
  char c[10];
  bool isChar;
  cout << "������һ����ĸ" << endl;
  cin.get(c, 10);
  if (strlen(c) > 1)
  {
    cout << "�����ַ���";
    return 0;
  }
  world = c[0];
  isChar = ((world >= 'a' && world <= 'z') || (world >= 'A' && world <= 'Z'));
  if (isChar)
  {
    if (world == 'a' || world == 'e' || world == 'i' || world == 'o' || world == 'u' || world == 'A' || world == 'E' || world == 'I' || world == 'O' || world == 'U')
      cout << c << "��Ԫ��";

    else
      cout << c << "�Ǹ���";
    return 0;
  }
  cout << "������ĸ" << endl;
  return 0;
}