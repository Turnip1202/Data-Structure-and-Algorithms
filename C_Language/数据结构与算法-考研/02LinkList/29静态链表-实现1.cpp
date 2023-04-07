#define MaxSize 10 // 静态链表的最大长度
struct Node
{           // 静态链表结构类型的定义
  int data; // 存储数据元素
  int next; // 下一个元素的数组下标
};

// 用数组定义多个连续存放的结点
void testSLinkList()
{
  struct Node a[MaxSize]; // 数组a作为静态链表, 每一个数组元素的类型都是struct Node
}
