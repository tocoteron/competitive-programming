#include <iostream>
#include <vector>
#include <map>
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
    assert(getGCD(2 * 3 * 5, 2 * 2 * 3 * 3) == 6);
}

// Complexity: O(log(min(a, b)))
long long getLCM(long long a, long long b)
{
    auto gcd = getGCD(a, b);

    return a * b / gcd;
}

void testGetLCM()
{
    assert(getLCM(1, 2) == 2);
    assert(getLCM(2, 6) == 6);
}

// Complexity: O(n^(1/2))
vector<pair<long long, long long> > getPrimeFactors(long long n)
{
    vector<pair<long long, long long> > res;

    for (long long i = 2LL; i * i <= n; ++i)
    {
        long long count = 0LL;

        while (n % i == 0LL)
        {
            n /= i;
            ++count;
        }

        if (count > 0)
        {
            res.push_back(make_pair(i, count));
        }
    }

    if (n > 1LL)
    {
        res.push_back(make_pair(n, 1LL));
    }

    return res;
}

void testGetPrimeFactors()
{
    vector<pair<long long, long long> > res{
        make_pair(2, 1),
        make_pair(3, 2),
        make_pair(5, 3)
    };

    assert(getPrimeFactors(2 * 3 * 3 * 5 * 5 * 5) == res);
}

int main()
{
    testGetDivisors();
    testGetGCD();
    testGetLCM();
    testGetPrimeFactors();

    return 0;
}