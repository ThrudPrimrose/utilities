#include "Utilities.hpp"

int64_t util::pow(int base, unsigned int exp)
{
    if (base == 2)
    {
        int64_t tmp = static_cast<int64_t>(base) << exp;
        return tmp;
    }

    int64_t result = 1;
    int iter = 0;
    while (true)
    {
        ++iter;

        if (exp & 1)
        {
            result *= base;
        }

        exp >>= 1;

        if (!exp)
        {
            break;
        }

        base *= base;
    }

    return result;
}

std::chrono::_V2::steady_clock::time_point util::timepoint() { return std::chrono::steady_clock::now(); }

double util::time_difference_in_seconds(std::chrono::_V2::steady_clock::time_point &beg)
{
    auto nw = std::chrono::steady_clock::now();
    size_t dur = std::chrono::duration_cast<std::chrono::nanoseconds>(nw - beg).count();
    double durd = static_cast<double>(dur) / 1000000000.0;
    return durd;
}
