#include "iostream"
using namespace std;
int main()
{
  int rows;
  cout << "请输入行号:";
  cin >> rows;
  // 外行内列
  for (int i = 1; i <= rows; ++i)
  {
    for (int j = 1; j <= i; ++j)
      cout << j << " ";
    cout << endl;
  }

  return 0;
}