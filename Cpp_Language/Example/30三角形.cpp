#include "iostream"
using namespace std;
int main()
{
  int space, rows;
  cout << "ÇëÊäÈëÐÐºÅ:" << endl;
  cin >> rows;
  for (int i = rows; i >= 1; --i)
  {
    for (int j = i; j > 1; --j)
      cout << "  ";
    for (int k = 1; k <= 2 * (rows - i + 1) - 1; ++k)
      cout << " " << k;
    cout << endl;
  }
  return 0;
}