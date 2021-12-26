
#include <iostream>


template <typename T>
T max(T first, T second)
{
    return first > second ? first : second;
}


template <>
const char *max(const char *first, const char *second)
{
    std::cout << "specialization\n";
    return first > second ? first : second;
}


template <typename T>
class temp
{
public:
    temp(T X)
    {
        std::cout << "non char " << X << std::endl;
    }
};


template<>
class temp<char>
{
    public:
    temp(char x)
    {
std::cout << "char " << x << std::endl;
    } 
};


int main()
{
    std::cout << max(2, 3) << std::endl;
    std::cout << max(2.4, 5.8) << std::endl;
    std::cout << max<double>(2.4, 5.8) << std::endl;
    std::cout << max('2', '3') << std::endl;
    std::cout << max("long", "longer") << std::endl;

    temp<int> t1(5);
    temp<double> t2(4.54);
    temp<char> t3('g');
}