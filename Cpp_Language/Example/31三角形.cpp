#include "iostream"
using namespace std;
int main()
{
  int space, rows;
  cout << "ÇëÊäÈëÐÐºÅ:" << endl;
  cin >> rows;
  for (int i = rows; i >= 1; --i)
  {

    for (int j = rows; j > i; --j)
      cout << "  ";
    for (int k = 2 * i - 1; k >= 1; --k)
      cout << " *";
    cout << endl;
  }
  return 0;
}