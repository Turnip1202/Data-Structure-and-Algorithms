struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}                   // 默认构造函数，用于初始化
  ListNode(int x) : val(x), next(nullptr) {}              // 实例化之后传入数据
  ListNode(int x, ListNode *next) : val(x), next(next) {} // 显示传入下一个节点
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    // 指向头结点
    ListNode *head = nullptr;
    // 可移动的指针
    *tail = nullptr;
    int carry = 0; // 记录进位
    // 下面的if会对链表指针移动，所以这里直接使用或
    while (l1 || l2)
    {
      // 如果两个链表的位数不等，则补零
      int n1 = l1 ? l1->val : 0;
      int n2 = l2 ? l2->val : 0;
      // 求和的时候要加上进位数
      int sum = n1 + n2 + carry;
      if (!head)
      {
        // 取余后的值，就是每位加后的结果了
        head = tail = new ListNode(sum % 10);
      }
      else
      {
        // 移动指针到下一个位置，next指向的是引用类型
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
      }
      carry = sum / 10;
      if (l1)
      {
        l1 = l1->next;
      }
      if (l2)
      {
        l2 = l2->next;
      }
    }
    if (carry > 0)
    {
      tail->next = new ListNode(carry);
    }
    return head;
  }
};
