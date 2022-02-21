#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 一个数组中只出现一次的数，其他的数出现3次

// 第一种方法就是直接hashmap搞统计

class Solution {
public:
    std::unordered_map<int, int> hash_map;
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto& i : nums)
        {
            ++hash_map[i];
        }
        for (auto& [num, count] : hash_map)
        {
            if (count == 1)
            {
                res = num;
                break;
            }
        }
        return res;
    }
};

//第二种方法就是 比如 数组为 3 3 3 1
// 3   0011
// 3   0011
// 3   0011
// 1   0001

// 我们用一个32位的数
class Solution_2
{
public:
    int singleNumber(vector<int>& nums)
    {
        int res = 0;
        for (int i = 0; i<32; ++i)
        {
            int count = 0;
            for (int num : nums)
            {
                count += (num>>i)&1;
            }
            if (count%3)
            {
                res |= (1<<i);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1,1,1,3,2,2,2};
    Solution_2 s;
    cout << s.singleNumber(v) << endl;
    return 0;
}
