#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

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

void testGetDivisors()
{
    vector<long long> res{1, 2, 4, 5, 10, 20, 25, 50, 100};
    assert(getDivisors(100) == res);
}

// Complexity: O(log(min(a, b)))
long long getGCD(long long a, long long b)
{
    long long tmp;
    while (b != 0LL)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

void testGetGCD()
{
    assert(getGCD(0, 2) == 2); // Unit is 0
    assert(getGCD(1, 2) == 1);
    assert(getGCD(30, 36) == 6);
}

int main()
{
    testGetDivisors();
    testGetGCD();

    return 0;
}