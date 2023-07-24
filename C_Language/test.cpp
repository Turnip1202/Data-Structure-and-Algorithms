#include "iostream"
#include "stdlib.h"
using namespace std;
typedef struct LNode
{
  /* data */
  int data;
  struct LNode *next;
} LNode, *LinkList;
// 初始化带头节点的单链表
void initLinkedList(LNode **head)
{
  // 创建头节点
  *head = (LNode *)malloc(sizeof(LNode));
  if (*head == NULL)
  {
    printf("内存分配失败！");
    return;
  }

  (*head)->data = 0; // 头节点的数据可以是任意值，这里设置为0
  (*head)->next = NULL;
}

// 向链表中插入元素（尾插法）
void insertElementTail(LNode *head, int element)
{
  LNode *newNode = (LNode *)malloc(sizeof(LNode));
  if (newNode == NULL)
  {
    printf("内存分配失败！");
    return;
  }

  newNode->data = element;
  newNode->next = NULL;

  LNode *current = head;
  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = newNode;
}

// 向链表中插入元素
void insertElement(LNode *head, int element)
{
  LNode *newNode = (LNode *)malloc(sizeof(LNode));
  if (newNode == NULL)
  {
    printf("内存分配失败！");
    return;
  }

  newNode->data = element;
  newNode->next = head->next;
  head->next = newNode;
}

void Sort(LinkList &L)
{
  LNode *p = L->next, *pre;
  LNode *r = p->next; // r保持*p后继结点指针，以保证不断链
  p->next = nullptr;  // 构造只包含一个数据结点的有序表
  p = r;
  while (p != nullptr)
  {
    r = p->next; // 保存*p的后继结点指针
    pre = L;
    while (pre->next != nullptr && pre->next->data < p->data)
      pre = pre->next;
    p->next = pre->next;
    pre->next = p;
    p = r;
  }
}
int main()
{
  LNode *head; // 定义头指针

  initLinkedList(&head); // 初始化带头节点的单链表

  // 向链表中插入10个元素
  for (int i = 1; i <= 10; i++)
  {
    insertElementTail(head, i);
  }
  // Sort(head);
  // 输出链表中的节点数据
  LNode *current = head->next;

  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
}