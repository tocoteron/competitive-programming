#include <iostream>

namespace TokorotenLab
{
    class Logger
    {
    private:
        bool isEnable;

    public:
        Logger(bool isEnable = true) : isEnable(isEnable) {}

        template<class T>
        Logger& operator<<(const T& val)
        {
            if(isEnable)
            {
                std::cout << val;
            }
            return *this;
        }

        void set_enable()
        {
            isEnable = true;
        }

        void set_disable()
        {
            isEnable = false;
        }

        void endl()
        {
            if(isEnable)
            {
                std::cout << std::endl;
            }
        }
    };

    Logger logger;
}

int main()
{
    (TokorotenLab::logger << 1 << " " << 2.0).endl();

    TokorotenLab::logger.set_disable();

    (TokorotenLab::logger << 3 << " " << 4.0).endl();
}
