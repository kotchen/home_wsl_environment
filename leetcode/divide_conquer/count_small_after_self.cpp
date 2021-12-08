#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
       for (auto i = nums.begin(); i!=nums.end(); i++) 
       {
            int count = 0;
           vector<int> temp(i, nums.end());
           sort(temp.begin(),temp.end());
           for (int j = 0; j<temp.size(); j++)
           {
               if (*i>temp[j]) count++;
               else break;
           }
           res.push_back(count);
       }
       return res;
  
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {2,0,1};
    for (auto i : s.countSmaller(v))
        std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}