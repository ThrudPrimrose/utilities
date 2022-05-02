#include <array>
#include "Utilities.hpp"
#include <vector>

namespace util
{

    template <typename ElementType, size_t Length>
    class HistoryArray
    {
    private:
        std::array<ElementType, Length> elements;
        size_t current_offset;
        size_t element_count;

    public:
        Historyrray() noexcept : elements{}, current_offset{0}, element_count{0} {};

        void insert(ElementType el);

        std::vector<ElementType> get_elements_vec();

        ElementType get_decaying_sum(unsigned int decay_factor);
    };

}

template <typename ElementType, size_t Length>
void util::HistoryArray<ElementType, Length>::insert(ElementType el)
{
    elements[current_offset] = el;

    current_offset = (current_offset + 1) % Length;
    element_count = std::min(element_count + 1, Length);
}

template <typename ElementType, size_t Length>
std::vector<ElementType> util::HistoryArray<ElementType, Length>::get_elements_vec()
{
    std::vector<ElementType> elvec;
    elvec.reserve(element_count);
    for (size_t i = 0; i < element_count; i++)
    {
        elvec.push_back(elements[i]);
    }
    return elvec;
}
template <typename ElementType, size_t Length>
ElementType util::HistoryArray<ElementType, Length>::get_decaying_sum(unsigned int decay_factor)
{
    if (current_offset == 0 && element_count == 0)
    {
        return 1;
    }

    size_t beg = 0;
    if (current_offset == 0 && element_count != 0)
    {
        beg = Length - 1;
    }
    else
    {
        beg = current_offset - 1;
    }

    ElementType sum = 0;
    size_t rem_count = element_count;
    size_t distance = 0;
    while (beg != current_offset && rem_count > 0)
    {

        sum += static_cast<ElementType>((static_cast<float>(elements[i])) /
                                        (static_cast<float>(util::intPow(decay_factor, distance))));

        if (beg == 0)
        {
            beg = Length - 1;
        }
        else
        {
            beg = beg - 1;
        }

        rem_count -= 1;
        distance += 1;
    }

    return sum;
}