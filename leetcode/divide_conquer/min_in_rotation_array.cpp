#include <iostream>
#include <vector>
using namespace std;
// class Solution {
// public:
//     int findMin(std::vector<int>& nums) {
//         int res = nums[0];
//         for (int i=0;i+1<nums.size();i++)
//         {
//             if (nums[i]>nums[i+1]) return nums[i+1];
//         }
//         return res;
//     }
// };
//  有相同元素
class Solution {
public:

    int helper(vector<int>& nums, int left, int right)
    {
        if (left >= right) return std::min(nums[left],nums[right]);
        int mid = (left+right)/2;
        return std::min(helper(nums,left,mid),
                        helper(nums, mid+1, right));
    }

    int findMin(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};

// class Solution {
// public:

//     int helper(vector<int>& nums, int left, int right)
//     {
//         if (nums[left]<=nums[right])
//         {
//             return nums[left];
//         }
//         int mid = (left+right)/2;
//         return std::min(helper(nums, left, mid),
//                         helper(nums, mid+1, right));
//     }

//     int findMin(vector<int>& nums) {
//         return helper(nums,0,nums.size()-1);
//     }
// };

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {3,1,3};
    std::cout << s.findMin(v) << '\n';
    return 0;
}
