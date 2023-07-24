#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���ڱ�ʾͼ�Ľڵ�
struct Node
{
  int value;                // �ڵ��ֵ
  vector<Node *> neighbors; // �ڵ���ھ�
  int inDegree;             // �ڵ�����

  Node(int val) : value(val), inDegree(0) {}
};

// ִ����������
vector<int> topologicalSort(vector<Node *> &graph)
{
  vector<int> result;
  queue<Node *> zeroInDegreeQueue;

  // ����ÿ���ڵ�����
  for (Node *node : graph)
  {
    for (Node *neighbor : node->neighbors)
    {
      neighbor->inDegree++;
    }
  }

  // �����Ϊ0�Ľڵ�������
  for (Node *node : graph)
  {
    if (node->inDegree == 0)
    {
      zeroInDegreeQueue.push(node);
    }
  }

  // ִ����������
  while (!zeroInDegreeQueue.empty())
  {
    Node *node = zeroInDegreeQueue.front();
    zeroInDegreeQueue.pop();
    result.push_back(node->value);

    // �����ھӽڵ�����
    for (Node *neighbor : node->neighbors)
    {
      neighbor->inDegree--;

      // ����ھӽڵ����ȱ�Ϊ0������������
      if (neighbor->inDegree == 0)
      {
        zeroInDegreeQueue.push(neighbor);
      }
    }
  }

  return result;
}

int main()
{
  // ����ͼ�Ľڵ�
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);
  Node *node5 = new Node(5);

  // ����ͼ�Ĺ�ϵ
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node3);
  node2->neighbors.push_back(node3);
  node2->neighbors.push_back(node4);
  node3->neighbors.push_back(node4);
  node4->neighbors.push_back(node5);

  // ����ͼ
  vector<Node *> graph = {node1, node2, node3, node4, node5};

  // ִ����������
  vector<int> result = topologicalSort(graph);

  // �������������
  cout << "������������";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  // �ͷŽڵ��ڴ�
  for (Node *node : graph)
  {
    delete node;
  }

  return 0;
}
