#include "divisors.h"
#include <cassert>

void testGetDivisors()
{
    vector<long long> res{1, 2, 4, 5, 10, 20, 25, 50, 100};
    assert(getDivisors(100) == res);
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