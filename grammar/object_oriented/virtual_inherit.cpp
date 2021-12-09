#include <cstdio>
#include <iostream>
class A
{
public:
    int a;
    int aa;
    virtual void vfuna(){};
};

class B: public virtual A
{
public:
    int b;
    int bb;
    virtual void vfunb(){};
};

class C: public virtual A
{
public:
    int c;
    int cc;
    void vfuna(){};
};

class D: public virtual B,public C
{
public:
    int d;
    int dd;
    void vfuna(){};
};



int main(int argc, char** argv)
{
    // printf("%ld\n", sizeof(C));

    // C c;
    // c.a = 0xaaaaaaaa;
    // c.aa = 0xbbbbbbbb;
    // c.b = 0xdddddddd;
    // c.bb = 0xeeeeeeee;
    // c.c = 0x11111111;
    // c.cc = 0x22222222;
    // C* pc = &c;
    // printf("%08x\n", pc);

    std::cout << sizeof(A) << '\n';
    std::cout << sizeof(B) << '\n';
    std::cout << sizeof(C) << '\n';
    std::cout << sizeof(D) << '\n';
}