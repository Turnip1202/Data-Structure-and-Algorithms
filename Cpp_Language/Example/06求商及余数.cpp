#include "iostream"
using namespace std;
int main()
{
  int divisor, dividend, quotient, remainder;
  cout << "���뱻����:" << endl;
  cin >> dividend;
  cout << "�������:" << endl;
  cin >> divisor;
  quotient = dividend / divisor;
  remainder = dividend % divisor;
  cout << "��=" << quotient << endl;
  cout << "����=" << remainder;
  return 0;
}