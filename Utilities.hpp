#pragma once
#include <chrono>

namespace util
{
    int64_t pow(int x, unsigned int p);
    std::chrono::_V2::steady_clock::time_point timepoint();
    double time_difference_in_seconds(std::chrono::_V2::steady_clock::time_point &beg);
};