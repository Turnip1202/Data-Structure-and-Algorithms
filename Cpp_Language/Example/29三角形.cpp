#include "iostream"
using namespace std;
int main()
{
  int space, row;
  cout << "�������к�:" << endl;
  cin >> row;
  // ������
  for (int i = row; i >= 1; --i)
  {
    // ����ո�
    for (int j = i; j > 1; --j)
      cout << "  ";
    // ����Ǻ�
    for (int k = 1; k <= 2 * (row - i + 1) - 1; ++k)
      cout << " *";
    cout << endl;
  }
  return 0;
}