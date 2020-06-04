#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complexity: O(N^(1/2) * log(N^(1/2))
vector<long long> getDivisors(long long n)
{
    vector<long long> res;

    for (long long i = 1LL; i * i <= n; ++i)
    {
        if (n % i == 0LL)
        {
            res.push_back(i);
            res.push_back(n / i);
        }
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    return res;
}

int main()
{
    auto divisors = getDivisors(100);

    for (const auto& d : divisors)
    {
        cout << d << endl;
    }

    return 0;
}