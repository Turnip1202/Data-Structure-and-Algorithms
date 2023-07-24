#include "iostream"
using namespace std;
void change(int *p, int *q)
{
  int ch;
  ch = *p;
  *p = *q;
  *q = ch;
}
int main()
{
  int a, b;
  int *p1, *p2;
  cout << "Please input two numbers:" << endl;
  cin >> a >> b;
  p1 = &a;
  p2 = &b;
  change(p1, p2);
  cout << "After changing:" << endl;
  cout << *p1 << " " << *p2 << endl;
  return 0;
}