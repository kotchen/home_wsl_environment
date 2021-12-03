#ifndef __kotchen_smart_pointer__
#define __kotchen_smart_pointer__
#include <iostream>
#include <memory>
namespace kotchen
{
template<typename T>
class shared_ptr
{
public:
    int* counter;
    int* weak_ref;
    T*   data;
public:
    // ptr = shared_ptr(e);
    // ptr = shared_ptr();

    shared_ptr(T* resourse = nullptr)
    {
        data = resourse;
        counter = new int(1);
        weak_ref = new int(0);
    }

    shared_ptr(shared_ptr& rhs)
    {
        counter = rhs.counter;
        data = rhs.data;
        ++*counter;
    }

    shared_ptr& operator= (shared_ptr& rhs)
    {
        --*counter;
        if (*counter==0)
        {
            delete data;
            delete counter;
            delete weak_ref;
        }
        data = rhs.data;
        counter = rhs.counter;
        ++*counter;
        return *this;
    }

    ~shared_ptr()
    {
        --*counter;
        if (( *counter ) == 0)
        {
            delete counter;
            delete data;
            delete weak_ref;
        }
    }
};


template<typename T>
class weak_ptr
{
public:
    T* data;
public:
    weak_ptr(T* resource=nullptr):data(resource)
    {
    }
    
    weak_ptr(shared_ptr<T> p)
    {
        data = p.data;
    }

    weak_ptr& operator= (shared_ptr<T> p)
    {
        data = p.data;
        *(p.weak_ref)++;
        return *this;
    }
};

struct Entity
{
    double x;
    double y;
    Entity() : x(0), y(0) {}
    void move_right(double offset)
    {
        x+=offset;
    }
};

void bar(std::unique_ptr<Entity> ptr)
{
    ptr->move_right(5);
}

void foo()
{
    auto e = std::make_unique<Entity>();
    e->move_right(2);
    bar(std::move(e));    
}

// std::unique_ptr
// auto e = std::make_unique<>();
class Son;

class Father {
public:
    shared_ptr<Son> son_;
    Father() {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~Father() {
        std::cout << __FUNCTION__ << std::endl;
    }
};

class Son {
public:
    weak_ptr<Father> father_;
    Son() {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~Son() {
        std::cout << __FUNCTION__ << std::endl;
    }
};
};




#endif

// int main(int argc, char const *argv[])
// {
//     // auto son = std::make_shared<Son>();
//     // auto father = std::make_shared<Father>();
//     // son->father_ = father;
//     // father->son_ = son;
//     // std::cout << "son: " << son.use_count() << std::endl;
//     // std::cout << "father: " << father.use_count() << std::endl;

//     // Son* son = new Son();
//     // Father* father = new Father();

//     // share_ptr<Son> s(son);
//     // share_ptr<Father> f(father); 
//     // s.data->father_ = f;
//     // f.data->son_ = s; 
//     auto son_ = new Son();  // 创建一个Son对象，返回指向Son对象的指针son_
//     auto father_ = new Father();  // 创建一个Father对象，返回指向Father对象的指针father_
//     share_ptr<Son> son(son_);  // 调用SharedPtr构造函数：son.counter=1, son.weakref=0
//     share_ptr<Father> father(father_);  // 调用SharedPtr构造函数：father.counter=1, father.weakref=0
//     son.data->father_ = father;  // 调用WeakPtr赋值函数：father.counter=1, father.weakref=1
//     father.data->son_ = son;  // 调用SharedPtr赋值函数：son.counter=2, son.weakref=0

//     return 0;
// }