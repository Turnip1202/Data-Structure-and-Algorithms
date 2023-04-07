#define MaxSize 10 // 定义最大长度
typedef struct
{
  int data[MaxSize]; // 使用静态的数组存放数据元素
  int length;        // 顺序表的当前长度
} SqList;

// 初始化顺序表
void InitList(SqList &L)
{
  L.length = 0; // 顺序表初长度为0
}
int main()
{
  SqList L;    // 声明一个顺序表
  InitList(L); // 初始化顺序表
  return 0;
}
