#include "iostream"
using namespace std;
int main()
{
  int space, row;
  cout << "请输入行号:" << endl;
  cin >> row;
  // 控制行
  for (int i = row; i >= 1; --i)
  {
    // 输出空格
    for (int j = i; j > 1; --j)
      cout << "  ";
    // 输出星号
    for (int k = 1; k <= 2 * (row - i + 1) - 1; ++k)
      cout << " *";
    cout << endl;
  }
  return 0;
}