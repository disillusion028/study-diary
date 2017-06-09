#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;
template<typename It>
auto fcn2(It beg,It end)->
    typename remove_reference<decltype(*beg)>::type
{
    return *beg;
}