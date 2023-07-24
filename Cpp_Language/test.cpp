#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
private:
  std::vector<int> parent; // 记录每个元素的父节点
  std::vector<int> rank;   // 记录每个集合的秩（用于优化合并操作）

public:
  UnionFind(int size)
  {
    // 初始化并查集，创建一个大小为size的集合，每个元素都是独立的根节点
    parent.resize(size);
    rank.resize(size, 0);

    for (int i = 0; i < size; i++)
    {
      parent[i] = i;
    }
  }

  int find(int x)
  {
    // 查找元素x所属的集合的根节点，并进行路径压缩优化
    if (parent[x] != x)
    {
      parent[x] = find(parent[x]); // 路径压缩，将x的父节点设为根节点
    }
    return parent[x];
  }

  void unionSets(int x, int y)
  {
    // 合并两个集合，将y所在集合的根节点设为x所在集合的根节点
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY)
    {
      if (rank[rootX] < rank[rootY])
      {
        parent[rootX] = rootY;
      }
      else if (rank[rootX] > rank[rootY])
      {
        parent[rootY] = rootX;
      }
      else
      {
        parent[rootY] = rootX;
        rank[rootX]++;
      }
    }
  }
};
int main()
{
  UnionFind uf = UnionFind(5);
  cout << uf.find(3) << endl;
  return 0;
}