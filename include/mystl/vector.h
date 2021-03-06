#ifndef __kotchen_vector__
#define __kotchen_vector__
#include <cstring>
namespace kotchen
{
    template<typename ValueT>
    class vector
    {
    public:
        using value_type             =   ValueT;
        using reference              =   ValueT&;
        using const_reference        =   const ValueT&;

    public:
        using iterator               =   ValueT*;
        using const_iterator         =   const ValueT*;
        using size_type              =   size_t;
        using difference_type        =   ptrdiff_t;
    private:
        iterator        m_data;
        iterator        m_begin;
        iterator        m_end;
        size_t          m_size;
        size_t          m_capacity;
    
    public:
        // 构造函数， 拷贝构造， 移动构造   
        vector():m_data(nullptr),m_begin(nullptr),m_end(nullptr),m_size(0),m_capacity(2) 
        {
            m_data = static_cast<ValueT*>(::operator new (m_capacity*sizeof(ValueT))); 
            m_begin = m_data;
            m_end = m_data;
        }
    
        vector(const vector& v):m_size(v.m_size), m_capacity(v.m_capacity)
        {
            m_data = static_cast<ValueT*>(::operator new (m_capacity*sizeof(ValueT)));
    
            m_begin = m_data;
            m_end   = m_data;
            for (size_t i = 0; i < m_size; i++)
            {
                ::new (&m_data[i]) ValueT(v.m_data[i]);
                m_end++;
            }
        }

        vector(vector&& rhs)
        {
            m_data = rhs.m_data;
            m_begin = rhs.m_begin;
            m_end = rhs.m_end;
            m_size = rhs.m_size;
            m_capacity = rhs.m_capacity;

            rhs.m_data = nullptr;
            rhs.m_begin = nullptr;
            rhs.m_end = nullptr;
            rhs.m_size = 0;
            rhs.m_capacity = 0;
        }
   
        ~vector()
        {
            for (iterator i = m_begin;i < m_end; i++ )
            {
                i->~ValueT();
            }
            ::operator delete (m_data);
            m_begin    = nullptr;
            m_end      = nullptr;
            m_size     = 0;
            m_capacity = 0;
        }

        template <typename Args>
        void push_back(Args&& val)
        {
            if (m_size<m_capacity)
            {
                // ::new(m_end) ValueT(std::forward<Args>(val)...);
                ::new(m_end) ValueT(std::forward<Args>(val));
                m_end++;
                m_size++;
            }
            else
            {
                m_capacity = m_capacity * 2;
                iterator new_area = static_cast<ValueT*> (::operator new(m_capacity*sizeof(ValueT))); 
                size_t new_size = 0;

                try
                {
                    for (size_t i = 0; i < m_size; i++)
                    {
                        ::new(&new_area[i]) ValueT(std::move(m_data[i]));
                        // ::new(&new_area[i]) ValueT(m_data[i]);
                        new_size++;
                    }
                }
                catch(...)
                {
                    for (size_t i = 0; i < new_size; i++)
                    {
                        new_area[i].~ValueT();
                    }
                    ::operator delete(new_area);
                    throw;
                }

                // for (size_t i = 0; i < m_size; i++)
                // {
                //     m_data[i].~ValueT();
                // }


                ::operator delete(m_data);
                m_data  = new_area;
                m_size  = new_size;
                m_begin = m_data;
                ::new(&m_data[m_size++]) ValueT(std::forward<Args>(val));
                m_end   = m_data + m_size;
            }
        }
        iterator begin()          {return m_begin;}
        iterator begin()    const {return m_begin;}

        iterator end()      const {return m_end;}

        size_t   size()     const {return m_size;}

        size_t   capacity() const {return m_capacity;}
    };

    
};



#endif


// int main()
//     {
//         // vector<std::string> vec;
//         // vec.push_back("hello");
//         // auto s = new std::string("hello");
   
//         // vec.push_back(*s);
//         // vec.push_back("world");
//         // std::vector<std::string> vec;
//         // vec.emplace_back("hello", 3);
//         // delete s;
//         // for (auto& i : vec)
//         // {
//         //     std::cout << i << std::endl;
//         // }
//         string s("hello");
//         //string s2("hello2");
//         vector<string> vec;
//         vec.push_back(s);
//         //vec.push_back(s2);
//         //string s3("qwe");
//         vec.push_back(string("qwe"));
//         for (string& i : vec)
//         {
//             std::cout << i.c_str() << std::endl;
//         }
//         // vector<std::string> vec_copy(std::move(vec));
//         // for (auto& i : vec_copy)
//         // {
//         //     std::cout << i << std::endl;
//         // }


//         // vector<string> vec;
//         // string string1;
//         // vec.push_back(string1);
//         // vec.push_back(string());

//     }