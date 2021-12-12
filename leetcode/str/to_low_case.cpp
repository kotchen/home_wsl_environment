#include <string>
using namespace std;
class Solution {
public:
    int offset = 'a' - 'A';
    string toLowerCase(string s) {
        for (int i = 0; i<s.size(); i++)
        {
            if (s[i]>='A'&& s[i]<='Z')
                s[i] = s[i] + offset;
        }
        return s;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
