#include "divisors.h"
#include <cassert>

void testGetFactors()
{
    vector<long long> res{1, 2, 4, 5, 10, 20, 25, 50, 100};
    assert(getFactors(100) == res);
}

void testGetGCD()
{
    assert(getGCD(0, 2) == 2); // Unit is 0
    assert(getGCD(1, 2) == 1);
    assert(getGCD(2 * 3 * 5, 2 * 2 * 3 * 3) == 6);
}

void testGetLCM()
{
    assert(getLCM(1, 2) == 2);
    assert(getLCM(2, 6) == 6);
}

void testIsPrime()
{
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(!isPrime(6));
}

void testGetPrimes()
{
    vector<long long> res{2, 3, 5, 7};
    assert(getPrimes(10) == res);
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

void testGetModInv()
{
    assert(getModInv(2, 3) == 2);
    assert(getModInv(4, 5) == 4);
}

int main()
{
    testGetFactors();
    testGetGCD();
    testGetLCM();
    testIsPrime();
    testGetPrimes();
    testGetPrimeFactors();
    testGetModInv();

    return 0;
}