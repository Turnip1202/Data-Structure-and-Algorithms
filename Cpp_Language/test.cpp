#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
private:
  std::vector<int> parent; // ��¼ÿ��Ԫ�صĸ��ڵ�
  std::vector<int> rank;   // ��¼ÿ�����ϵ��ȣ������Ż��ϲ�������

public:
  UnionFind(int size)
  {
    // ��ʼ�����鼯������һ����СΪsize�ļ��ϣ�ÿ��Ԫ�ض��Ƕ����ĸ��ڵ�
    parent.resize(size);
    rank.resize(size, 0);

    for (int i = 0; i < size; i++)
    {
      parent[i] = i;
    }
  }

  int find(int x)
  {
    // ����Ԫ��x�����ļ��ϵĸ��ڵ㣬������·��ѹ���Ż�
    if (parent[x] != x)
    {
      parent[x] = find(parent[x]); // ·��ѹ������x�ĸ��ڵ���Ϊ���ڵ�
    }
    return parent[x];
  }

  void unionSets(int x, int y)
  {
    // �ϲ��������ϣ���y���ڼ��ϵĸ��ڵ���Ϊx���ڼ��ϵĸ��ڵ�
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