#define MaxSize 10 // ������󳤶�
typedef struct
{
  int data[MaxSize]; // ʹ�þ�̬������������Ԫ��
  int length;        // ˳���ĵ�ǰ����
} SqList;

// ��ʼ��˳���
void InitList(SqList &L)
{
  L.length = 0; // ˳��������Ϊ0
}
int main()
{
  SqList L;    // ����һ��˳���
  InitList(L); // ��ʼ��˳���
  return 0;
}
