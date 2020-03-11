#include <iostream>
#include <vector>
#include <algorithm>

namespace TokorotenLab
{
    template<class T>
    class CordinatesCompressor
    {
    private:
        std::vector<T> uniqued;
        std::vector<long long> compressed;

    public:
        CordinatesCompressor(const std::vector<T>& original) : uniqued(original), compressed(original.size())
        {
            std::sort(uniqued.begin(), uniqued.end());
            uniqued.erase(std::unique(uniqued.begin(), uniqued.end()), uniqued.end());
        }

        long long getCompressedIndex(T val)
        {
            return std::lower_bound(uniqued.begin(), uniqued.end(), val) - uniqued.begin();
        }
    };
}

// Sample code
int main()
{
    using namespace std;

    vector<int> data{1, 2, 5, 4, 4};
    TokorotenLab::CordinatesCompressor<int> compressor(data);

    for(const auto& v : data)
    {
        cout << "value: " << v << ", compressedIndex: " << compressor.getCompressedIndex(v) << endl;
    }
}