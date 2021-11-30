#include <iostream>

const char* str = "hello world!";
const char* sstr = "hello world!";


int main()
{
    const char* p = str;
    const char* pp = sstr;
    int a  = 0;
    int b  = 2;
    int c = 1;
    int d = 1;
    printf("%p %p\n", &p, &pp);
    
    printf("%p %p\n", &a, &b);
    printf("%p %p", &c, &d);
    std::cin.get();
}