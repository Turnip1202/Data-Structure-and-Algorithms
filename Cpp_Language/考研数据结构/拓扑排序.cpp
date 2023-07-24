#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 用于表示图的节点
struct Node
{
  int value;                // 节点的值
  vector<Node *> neighbors; // 节点的邻居
  int inDegree;             // 节点的入度

  Node(int val) : value(val), inDegree(0) {}
};

// 执行拓扑排序
vector<int> topologicalSort(vector<Node *> &graph)
{
  vector<int> result;
  queue<Node *> zeroInDegreeQueue;

  // 计算每个节点的入度
  for (Node *node : graph)
  {
    for (Node *neighbor : node->neighbors)
    {
      neighbor->inDegree++;
    }
  }

  // 将入度为0的节点加入队列
  for (Node *node : graph)
  {
    if (node->inDegree == 0)
    {
      zeroInDegreeQueue.push(node);
    }
  }

  // 执行拓扑排序
  while (!zeroInDegreeQueue.empty())
  {
    Node *node = zeroInDegreeQueue.front();
    zeroInDegreeQueue.pop();
    result.push_back(node->value);

    // 更新邻居节点的入度
    for (Node *neighbor : node->neighbors)
    {
      neighbor->inDegree--;

      // 如果邻居节点的入度变为0，将其加入队列
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
  // 创建图的节点
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);
  Node *node5 = new Node(5);

  // 构建图的关系
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node3);
  node2->neighbors.push_back(node3);
  node2->neighbors.push_back(node4);
  node3->neighbors.push_back(node4);
  node4->neighbors.push_back(node5);

  // 构建图
  vector<Node *> graph = {node1, node2, node3, node4, node5};

  // 执行拓扑排序
  vector<int> result = topologicalSort(graph);

  // 输出拓扑排序结果
  cout << "拓扑排序结果：";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  // 释放节点内存
  for (Node *node : graph)
  {
    delete node;
  }

  return 0;
}
