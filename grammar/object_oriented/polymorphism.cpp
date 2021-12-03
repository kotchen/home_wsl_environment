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

int main()
{
    Dog* speaker_1 = new Dog();
    Human* speaker_2 = new Human();
    Shiba* speaker_3 = new Shiba();

    Ispeaker* p1 = (Ispeaker*)speaker_1;
    Ispeaker* p2 = (Ispeaker*)speaker_2;
    Ispeaker* p3 = (Ispeaker*)speaker_3;

    p1->speak();
    p2->speak();
    p3->speak();

    Dog* p_dog = (Dog*)speaker_3;
    p1->Ispeaker::speak();

    
}