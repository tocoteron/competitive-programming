#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Complexity: O(N^(1/2) * log(N^(1/2))
vector<long long> getFactors(long long n)
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

// Complexity: O(n * log(log(n)))
// [2, n]
vector<long long> getPrimes(long long n)
{
    vector<long long> isPrime(n + 1, true);
    vector<long long> primes;

    for (long long i = 2LL; i * i <= n; ++i)
    {
        if (!isPrime[i])
        {
            continue;
        }

        for (long long j = i * 2; j <= n; j += i)
        {
            isPrime[j] = false;
        }
    }

    for (long long i = 2LL; i <= n; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
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