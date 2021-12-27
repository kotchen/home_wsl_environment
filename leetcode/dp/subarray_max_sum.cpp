#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dp;
    int maxSubArray(vector<int>& nums) {
        dp = nums;
        int res = nums[0];
        for (int i = 1; i<dp.size(); i++)
        {
            dp[i] = max(dp[i-1]+dp[i], dp[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
