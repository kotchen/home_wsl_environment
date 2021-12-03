#ifndef __kotchen_string__
#define __kotchen_string__

#include <cstring>

namespace kotchen
{
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
            if(data)
                ::operator delete(data);
			length = 0;
        }

        const char* c_str() const
        {
            return this->data;
        }
    };
};


#endif


// int main(int argc, char const *argv[])
// {
//     string s;
//     string s1("hello");
//     string s2 = s1;
//     string s3 = std::move(s1);
//     s3 = s2;
//     return 0;
// }