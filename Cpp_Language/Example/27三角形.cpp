#include "iostream"
using namespace std;
int main()
{
  int row;
  cout << "�������к�:";
  cin >> row;
  for (int i = row; i >= 1; --i)
  {
    // for (int j = i; j >= 1; --j)
    for (int j = 1; j <= i; ++j)
      cout << " *";
    cout << "\n";
  }
  return 0;
}