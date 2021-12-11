#include <string>
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    inline int helper(string& str, int start)
    {
        while (start<str.size() && str[start]!='.' ) start++;
        return start;
    }
    inline int str2int(string& str, int left, int right)
    {
        int res = 0;
        int length = right-left;
        for (int i = left; i<right; i++)
        {
            if (str[i] == '0')
            {
                length--;
                continue;
            } 
            res += (pow(10, --length) * (str[i]-48));
        }
        return res;
    }
    int compareVersion(string version1, string version2) {
        int index_1 = 0;
        int index_2 = 0;
        int value_1 = 0;
        int value_2 = 0;
        while (index_1<version1.size() && index_2<version2.size())
        {
            int end_1 = helper(version1, index_1);
            int end_2 = helper(version2, index_2);
            value_1 = str2int(version1, index_1, end_1);
            value_2 = str2int(version2, index_2, end_2);
            if (value_1 == value_2) 
            {
                index_1 = end_1+1;
                index_2 = end_2+1;
                continue;
            } 
            if (value_1>value_2) return 1;
            if (value_1<value_2) return -1;
        }
        if (index_1<version1.size())
        {
            for (int  i = index_1; i<version1.size(); i++)
                if (version1[i]!='.'&&version1[i]!='0') return 1;
        }
        else if (index_2<version2.size())
        {
            for (int  i = index_2; i<version2.size(); i++)
                if (version2[i]!='.'&&version1[i]!='0') return -1;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.compareVersion("1.01", "1.001"); 
    return 0;
}
