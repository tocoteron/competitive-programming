#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>

namespace TokorotenLab
{
    /*
    Arguments:
        Search range: [begin, end)
        Target function: f(x)
    Requirement:
        f(x) => { false, ..., false, true, ..., true }
    Judge:
        true_bound == begin => All f(x) are true
        true_bound == end => All f(x) are false
    */
    std::pair<long long, long long> binary_search(long long begin, long long end, std::function<bool(long long)> f)
    {
        long long false_bound = begin - 1LL; // ( ..., false_bound] => false
        long long true_bound = end; // [true_bound, ... ) => true
        long long x;

        while(true_bound - false_bound > 1LL)
        {
            x = false_bound + (true_bound - false_bound) / 2LL;
            if(f(x))
            {
                true_bound = x;
            }
            else
            {
                false_bound = x;
            }
        }

        return std::make_pair(false_bound, true_bound);
    }
}

using namespace std;

int main()
{
    return 0;
}
