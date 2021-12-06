#include <iostream>
class Base
{
public: 
    int32_t a;
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
class IRunner {
private:
	size_t a;
public:
	IRunner()
		: a(0){
	}
	virtual void run() = 0;
};

class ISpeaker{
protected:
	size_t b;
public:
	ISpeaker( size_t _v )
		: b(_v) 
	{}
	virtual void speak() = 0;
};

class Dog : public ISpeaker {
public:
	Dog()
		: ISpeaker(1)
	{}
	//
	virtual void speak() override {
		printf("woof! %lu\n", b);
	}
};

class RunnerDog : public IRunner, public Dog {
public:
	RunnerDog()
	{}

    virtual void speak()
    {
        printf("RunnerDog\n");
    }

	virtual void run() override {
		printf("run with 4 legs\n");
	}
};


int main(int argc, char const *argv[])
{
    auto pdog = new RunnerDog();
    ISpeaker* speaker = pdog;
    speaker->speak();
    return 0;
}
