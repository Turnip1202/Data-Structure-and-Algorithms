#include "iostream"
#include "stdlib.h"
using namespace std;
typedef struct LNode
{
  /* data */
  int data;
  struct LNode *next;
} LNode, *LinkList;
// ��ʼ����ͷ�ڵ�ĵ�����
void initLinkedList(LNode **head)
{
  // ����ͷ�ڵ�
  *head = (LNode *)malloc(sizeof(LNode));
  if (*head == NULL)
  {
    printf("�ڴ����ʧ�ܣ�");
    return;
  }

  (*head)->data = 0; // ͷ�ڵ�����ݿ���������ֵ����������Ϊ0
  (*head)->next = NULL;
}

// �������в���Ԫ�أ�β�巨��
void insertElementTail(LNode *head, int element)
{
  LNode *newNode = (LNode *)malloc(sizeof(LNode));
  if (newNode == NULL)
  {
    printf("�ڴ����ʧ�ܣ�");
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

// �������в���Ԫ��
void insertElement(LNode *head, int element)
{
  LNode *newNode = (LNode *)malloc(sizeof(LNode));
  if (newNode == NULL)
  {
    printf("�ڴ����ʧ�ܣ�");
    return;
  }

  newNode->data = element;
  newNode->next = head->next;
  head->next = newNode;
}

void Sort(LinkList &L)
{
  LNode *p = L->next, *pre;
  LNode *r = p->next; // r����*p��̽��ָ�룬�Ա�֤������
  p->next = nullptr;  // ����ֻ����һ�����ݽ��������
  p = r;
  while (p != nullptr)
  {
    r = p->next; // ����*p�ĺ�̽��ָ��
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
  LNode *head; // ����ͷָ��

  initLinkedList(&head); // ��ʼ����ͷ�ڵ�ĵ�����

  // �������в���10��Ԫ��
  for (int i = 1; i <= 10; i++)
  {
    insertElementTail(head, i);
  }
  // Sort(head);
  // ��������еĽڵ�����
  LNode *current = head->next;

  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
}