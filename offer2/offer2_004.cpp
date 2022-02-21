#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
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

int main(int argc, char const *argv[])
{
    vector<int> v{1,1,1,3,2,2,2};
    Solution s;
    cout << s.singleNumber(v) << endl;
    return 0;
}
