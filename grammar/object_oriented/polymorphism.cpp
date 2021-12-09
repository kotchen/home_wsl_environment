#include <iostream>

class Ispeaker
{
protected:
    size_t b;
public:
    Ispeaker(size_t _v) 
        : b(_v)
    {}
    virtual void speak() = 0;
};

void Ispeaker::speak()
{

}

class Dog : Ispeaker
{
private:
    int feet;
public:
    Dog() 
        : Ispeaker(0), feet(4)
    {}

    virtual void eat_shit()
    {
        printf("eat shit\n");
    }

    virtual void speak()
    {
        printf("dog! %lu\n", b);
    }
};

class Shiba : Dog
{
public:
    Shiba()
        : Dog()
    {}
    
    // virtual void speak()
    // {
    //     printf("Shiba\n");
    // }
};

class Human : Ispeaker
{
private:
    size_t c;
public:
    Human()
        : Ispeaker(1),
          c(2)
    {}

    virtual void speak()
    {
        printf("human! %lu\n", c);
    }
};

class Animal
{
public:
    virtual void eat();
};

class Mammal : public virtual Animal
{
public:
    virtual void breathe();
};

class WingedAnimal : public virtual Animal
{
public:
    virtual void flap();
};

// A bat is a winged mammal
class Bat : public Mammal, public WingedAnimal
{
};

template<typename T> class MakeFinally{
   private:
       MakeFinally(){};//只有MakeFinally的友类才可以构造MakeFinally
       ~MakeFinally(){};
   friend T;
};

class MyClass:public virtual  MakeFinally<MyClass>
{

};//MyClass是不可派生类

//由于虚继承，所以D要直接负责构造MakeFinally类，从而导致编译报错，所以D作为派生类是不合法的。
class D: public MyClass
{

};
//另外，如果D类没有实例化对象，即没有被使用，实际上D类是被编译器忽略掉而不报错

int main()
{
    // Dog* speaker_1 = new Dog();
    // Human* speaker_2 = new Human();
    // Shiba* speaker_3 = new Shiba();

    // Ispeaker* p1 = (Ispeaker*)speaker_1;
    // Ispeaker* p2 = (Ispeaker*)speaker_2;
    // Ispeaker* p3 = (Ispeaker*)speaker_3;

    // p1->speak();
    // p2->speak();
    // p3->speak();

    // Dog* p_dog = (Dog*)speaker_3;
    // p1->Ispeaker::speak();
    // Bat b;
    // Animal &a = b; // error: which Animal subobject should a Bat cast into,
    //                // a Mammal::Animal or a WingedAnimal::Animal?
    // Bat* pb = &b;
    // Animal* pa = pb;

    std::cout << sizeof (Animal) << '\n';
    std::cout << sizeof (Mammal) << '\n';
    std::cout << sizeof (WingedAnimal) << '\n';
    std::cout << sizeof (Bat) << '\n';



}