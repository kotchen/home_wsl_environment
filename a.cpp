#include <iostream>

class Base
{
public: 
    int a;
    char* b;

    Base() : a(0), b(nullptr) {};

    virtual ~Base()
    {
        if (b!=nullptr) free(b);
        b = nullptr;
    }

    virtual void qwe(int a){printf("this is Base\n");}

};


class Derived : Base
{
public:
    Derived()
    {
    }
    void print()
    {
        printf("%d\n", this->a);
    }

    virtual void qwe(int a) { printf("this is derived\n");}

    ~Derived()
    {
        
    }
};
int main ()   
{   
   Base* pa = new Base();
   Derived* pb = new Derived();
   pa->qwe(0);
   pb->qwe(0);
   delete pa;
   delete pb;
}