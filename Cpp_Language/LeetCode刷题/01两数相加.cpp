struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}                   // Ĭ�Ϲ��캯�������ڳ�ʼ��
  ListNode(int x) : val(x), next(nullptr) {}              // ʵ����֮��������
  ListNode(int x, ListNode *next) : val(x), next(next) {} // ��ʾ������һ���ڵ�
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    // ָ��ͷ���
    ListNode *head = nullptr;
    // ���ƶ���ָ��
    *tail = nullptr;
    int carry = 0; // ��¼��λ
    // �����if�������ָ���ƶ�����������ֱ��ʹ�û�
    while (l1 || l2)
    {
      // ������������λ�����ȣ�����
      int n1 = l1 ? l1->val : 0;
      int n2 = l2 ? l2->val : 0;
      // ��͵�ʱ��Ҫ���Ͻ�λ��
      int sum = n1 + n2 + carry;
      if (!head)
      {
        // ȡ����ֵ������ÿλ�Ӻ�Ľ����
        head = tail = new ListNode(sum % 10);
      }
      else
      {
        // �ƶ�ָ�뵽��һ��λ�ã�nextָ�������������
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
