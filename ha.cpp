#include <iostream>
#include <vector>
#include <cstring>
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

    iterator begin()    const {return m_begin;}

    iterator end()      const {return m_end;}

    size_t   size()     const {return m_size;}

    size_t   capacity() const {return m_capacity;}
};

class string
{
public:

    char* data;
    size_t length;
    
    string() : length(0)
    {
        data = static_cast<char*>(::operator new (sizeof(char)));
        *data = '\0';
    }

    string(const char* str) : length(strlen(str))
    {
        data = static_cast<char*>(::operator new ((strlen(str)+1)*sizeof(char)));
        memcpy(data,str,strlen(str));
        data[strlen(str)] = '\0';
    }

    string(const string& rhs) 
    {
        data = static_cast<char*>(::operator new ((rhs.length + 1) * sizeof(char)));
        memcpy(data,rhs.c_str(),rhs.length);
        data[rhs.length] = '\0';
        this->length = rhs.length;
    }

    string(string&& rhs) 
    {
        this->data       = rhs.data;
        this->length     = rhs.length;
        rhs.data         = nullptr;
        rhs.length       = 0;   
    }

    ~string()
    {
        ::operator delete(data);
    }

    const char* c_str() const
    {
        return this->data;
    }


    
};
int main()
{
   

}