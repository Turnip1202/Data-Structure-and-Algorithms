#include "iostream"
using namespace std;
int main()
{
  int a = 9, b = 4;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  // ����������������õ�һ���м�ֵ��
  // �������������е�����һ�����м�ֵ���ͻ�õ���һ������������
  a = a ^ b; // �õ�һ������ֵ
  b = a ^ b; // ����ֵ �� ԭֵ�������
  a = a ^ b;
  cout << "a:" << a << endl;
  cout << "b:" << b << endl;
  return 0;
}