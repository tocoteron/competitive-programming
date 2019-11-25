#include <iostream>
#include <functional>
#include <map>
#include <vector>

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

// Sample code
int main()
{
    using namespace std;

    vector<int> v;

    for(int i = 0; i < 1e6; ++i)
    {
        v.push_back(i);
    }

    auto result = TokorotenLab::binary_search(0, v.size(), [&](long long x) {
        return 1e4 <= v[x];
    });

    cout << "false_bound: " << result.first << endl;
    cout << "true_bound: " << result.second << endl;

    if(result.second == 0)
    {
        cout << "All f(x) are true" << endl;
    }
    else if(result.second == v.size())
    {
        cout << "All f(x) are false" << endl;
    }

    return 0;
}
