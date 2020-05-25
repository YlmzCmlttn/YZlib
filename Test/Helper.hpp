#include <random>
template<class T>
using uniform_distribution = 
typename std::conditional<
    std::is_floating_point<T>::value,
    std::uniform_real_distribution<T>,
    typename std::conditional<
        std::is_integral<T>::value,
        std::uniform_int_distribution<T>,
        void
    >::type
>::type;
template <class T>
T GetRand(T lower, T upper)
{
    static thread_local std::mt19937_64 mt(std::random_device{}());
    uniform_distribution<T> dist(lower,upper);
    return dist(mt);
}