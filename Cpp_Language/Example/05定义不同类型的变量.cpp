#include "iostream"
#include "string.h"
using namespace std;
int main()
{
  // ��������
  int myNum = 5;              // ����
  float myFloatNum = 5.99;    // �����ȸ�����
  double myDoubleNum = 9.98;  // ˫���ȸ�����
  char myLetter = 'D';        // �ַ���
  bool myBoolean = true;      // ������
  string myString = "Turnip"; // �ַ���

  // �������
  cout << "int:" << myNum << "\n";
  cout << "float:" << myFloatNum << endl;
  cout << "char:" << myLetter << endl;
  cout << "bool:" << myBoolean << endl;
  cout << "string:" << myString << "\n";
  return 0;
}