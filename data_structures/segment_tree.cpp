#include <vector>
#include <functional>
#include <cassert>

using namespace std;

// 0-indexed
template<typename T>
struct SegmentTree
{
    int n;
    vector<T> node;
    T e;
    function<T(T, T)> f;

    SegmentTree(vector<T> v, T e, function<T(T, T)> f) : e(e), f(f)
    {
        n = 1LL;
        while (n < v.size())
        {
            n *= 2;
        }

        node.resize(2 * n - 1, e);

        for (int i = 0; i < v.size(); ++i)
        {
            node[n - 1 + i] = v[i];
        }

        for (int i = n - 2; i >= 0; --i)
        {
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    void update(int i, T val)
    {
        i += n - 1;
        node[i] = val;

        while (i > 0)
        {
            i = (i - 1) / 2;
            node[i] = f(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    // [a, b)
    T get(int a, int b, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
        {
            r = n;
        }

        if (r <= a || b <= l)
        {
            return e;
        }

        if (a <= l && r <= b)
        {
            return node[k];
        }

        int left = get(a, b, 2 * k + 1, l, l + (r - l) / 2);
        int right = get(a, b, 2 * k + 2, l + (r - l) / 2, r);

        return f(left, right);
    }
};

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegmentTree<int> st(v, 0, [](int a, int b){
        return a + b;
    });

    assert(st.get(0, 10) == 55);
    assert(st.get(0, 5) == 15);
    assert(st.get(5, 10) == 40);
    assert(st.get(1, 9) == 44);
    assert(st.get(0, 1) == 1);
    assert(st.get(0, 0) == 0);
}