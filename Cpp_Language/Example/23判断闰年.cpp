#include "iostream"
using namespace std;
int main()
{
  int year;
  cout << "������һ�����:" << endl;
  cin >> year;
  if (year % 4 == 0)
    if (year % 100 == 0)
    {
      if (year % 400)
        cout << "��������";
      else
        cout << "������";
    }
    else
      cout << "������";
  else
    cout << "��������";

  return 0;
}