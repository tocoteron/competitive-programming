#include <vector>
#include <cassert>

using namespace std;

// 0-indexed
struct UnionFind
{
    vector<int> parents;
    vector<int> sizes;

    UnionFind(int elem_num) : parents(elem_num), sizes(elem_num, 1)
    {
        for (int i = 0; i < elem_num; ++i)
        {
            parents[i] = i;
        }
    }

    int find(int x)
    {
        if  (parents[x] == x)
        {
            return x;
        }

        return parents[x] = find(parents[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
        {
            return false;
        }

        if (sizes[a] > sizes[b])
        {
            swap(a, b);
        }

        sizes[b] += sizes[a];
        parents[a] = b;

        return true;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    int size(int x)
    {
        return sizes[find(x)];
    }
};

int main()
{
    UnionFind uf(10);

    assert(uf.size(0) == 1);
    assert(uf.same(0, 0));
    assert(uf.same(9, 9));

    uf.unite(0, 1);

    assert(uf.size(0) == 2);
    assert(uf.size(1) == 2);
    assert(uf.same(0, 1));
    assert(!uf.same(0, 9));

    return 0;
}