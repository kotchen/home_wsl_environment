#include <vector>

#include <iostream>
using namespace std;
// 归并排序
// class Solution {
// public:
//     vector<int> tmp;
//     void merge(vector<int>& nums, int l, int mid, int r)
//     {       
//         int cnt = 0;
//         int i = l;
//         int j = mid+1;
//         while (i <= mid && j <= r) {
//             if (nums[i] <= nums[j]) {
//                 tmp[cnt++] = nums[i++];
//             }
//             else {
//                 tmp[cnt++] = nums[j++];
//             }
//         }
//         while (i <= mid) {
//             tmp[cnt++] = nums[i++];
//         }
//         while (j <= r) {
//             tmp[cnt++] = nums[j++];
//         }
//         for (int i = 0; i < r - l + 1; ++i) {
//             nums[i + l] = tmp[i];
//         }
//     }

//     void merge_sort(vector<int>& nums, int left, int right)
//     {
//         if (left == right) return;
//         if (left+1 == right) 
//         {
//             if (nums[left]>nums[right])
//                 std::swap(nums[left], nums[right]);
//             return ;
//         }
//         int mid = (left+right)/2;
//         merge_sort(nums, left, mid);
//         merge_sort(nums, mid+1, right);
//         merge(nums, left, mid, right);
//     }
//     vector<int> sortArray(vector<int>& nums) {
//         tmp.resize(nums.size(),0);
//         merge_sort(nums, 0, nums.size()-1);
//         return nums;
//     }
// };
// 快排
// 快排的关键就是随机找一个数，作为pivot，然后调整整个数组，使得pivot左边的数都小于pivot，右边的数都大于它
// 然后进行递归，左边排一次右边排一次
// class Solution {
// public:
//     void qsort(vector<int>& nums, int left, int right)
//     {
//         if (left>=right) return; 
//         int l = left, r = right;
//         int pivot = rand()%(right-left+1)+left;
//         std::swap(nums[left], nums[pivot]);
//         pivot = nums[left];
//         while (left < right)
//         {
//             while (left < right && nums[right]>=pivot)
//                 right--;
//             nums[left] = nums[right];
//             while (left < right && nums[left]<=pivot)
//                 left++;
//             nums[right] = nums[left];
//         }
//         nums[right] = pivot;
//         qsort(nums, l, left-1);
//         qsort(nums, left+1, r);
//     }
//     vector<int> sortArray(vector<int>& nums) {
//         qsort(nums, 0, nums.size()-1);
//         return nums;
//     }
// };

class Solution {
    void head_down(int i,int size,vector<int>& nums)
    {
        while(i<size)
        {
            int left=2*i+1,right=2*i+2;
            int max=i;
            if(left<size&&nums[left]>nums[max])
                max=left;
            // right<size是防止nums越界，因为可能下标对于的节点是空的
            if(right<size&&nums[right]>nums[max])
                max=right;
            if(max==i)
                break;
            swap(nums[i],nums[max]);
            i=max;
        }
    }
    void maxHeapity(vector<int>& nums,int size)
    {
        for(int i=size/2-1;i>=0;i--)
            head_down(i,size,nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        maxHeapity(nums,n);
        swap(nums[0],nums[n-1]);
        for(int i=n-2;i>0;i--)
        {
            n--;
            head_down(0,n,nums);
            swap(nums[0],nums[i]);
        }
        return nums;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {5,2,3,1};
    for (auto i : s.sortArray(v))
        std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}
