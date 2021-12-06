#include <iostream>
#include <vector>
#include <algorithm>
// 自相残杀
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
       int count = 0;
       int res = nums[0];
       for (auto i : nums)
       {
           if (i==res)
            {
                count++;
                i = res;
            }
           else count--;
           if (count==-1)
           {
               count = 1;
               res = i;
           }
       }
       return res;
    }
};
// class Solution {
// public:
//     int majorityElement(std::vector<int>& nums) {
//         std::sort(nums.begin(), nums.end());
//         return nums[nums.size()/2];
//     }
// };
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
