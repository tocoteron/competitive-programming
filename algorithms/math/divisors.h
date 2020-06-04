#include <iostream>
#include <vector>
#include <map>
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

// Complexity: O(log(min(a, b)))
long long getLCM(long long a, long long b)
{
    auto gcd = getGCD(a, b);

    return a * b / gcd;
}

// Complexity: O(n^(1/2))
bool isPrime(long long n)
{
    if (n == 1LL)
    {
        return false;
    }

    for (long long i = 2LL; i * i <= n; ++i)
    {
        if (n % i == 0LL)
        {
            return false;
        }
    }

    return true;
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