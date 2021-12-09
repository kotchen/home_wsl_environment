#include <cstdio>

class A
{
public:
    int a;
    int aa;
    virtual void vfuna(){};
};

class B
{
public:
    int b;
    int bb;
    virtual void vfunb(){};
};

class C: virtual public A,virtual public B
{
public:
    int c;
    int cc;
    void vfuna(){};
};


int main(int argc, char** argv)
{
    printf("%d\n", sizeof(C));

    C c;
    c.a = 0xaaaaaaaa;
    c.aa = 0xbbbbbbbb;
    c.b = 0xdddddddd;
    c.bb = 0xeeeeeeee;
    c.c = 0x11111111;
    c.cc = 0x22222222;
    C* pc = &c;
    printf("%08x\n", pc);
}