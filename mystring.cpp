#include <cstring>
#include <iostream>
class string 
{
public:
string()
{
	length = 0;
	m_data = new char[1];
	*m_data = '\0';
}

string(const char* str)
{
    length = strlen(str);
    m_data = new char[length+1];
    for (int i = 0; i<length; i++)
    {
        m_data[i] = str[i]; 
    }
    m_data[length] = '\0';
}

string(const string& str)
{
	length = str.length;
	m_data = new char[length+1];
	for (int i = 0; i<length; i++)
	{
		m_data[i] = str.m_data[i];
	}
	m_data[length] = '\0';
}

string(string&& rstr)
{
	length = rstr.length;
	m_data  = rstr.m_data;
	rstr.m_data = nullptr;
	length = 0;
}

string& operator= (const string& str)
{
	if (m_data == str.m_data) return *this;
    delete[] m_data;
    m_data = new char[str.length+1];
    length = str.length;
    for (int i = 0; i<length; i++)
	{
		m_data[i] = str.m_data[i];
	}
    m_data[length] = '\0';
    return *this;
}

~string()
{
	if (m_data==nullptr){}
	else
	{
		delete[] m_data;
		length = 0;
	}
}

private:
char* m_data;
int length;
};

int main(int argc, char const *argv[])
{
    string s;
    string s1("hello");
    string s2 = s1;
    string s3 = std::move(s1);
    s3 = s2;
    return 0;
}
