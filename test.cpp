#include <iostream>

const char* str = "hello world!";
const char* sstr = "hello world!";


int main()
{
    auto p = str;
    auto pp = sstr;
    printf("%p %p", str, sstr);
    std::cin.get();
}