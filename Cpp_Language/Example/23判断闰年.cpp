#include "iostream"
using namespace std;
int main()
{
  int year;
  cout << "请输入一个年份:" << endl;
  cin >> year;
  if (year % 4 == 0)
    if (year % 100 == 0)
    {
      if (year % 400)
        cout << "不是闰年";
      else
        cout << "是闰年";
    }
    else
      cout << "是闰年";
  else
    cout << "不是闰年";

  return 0;
}