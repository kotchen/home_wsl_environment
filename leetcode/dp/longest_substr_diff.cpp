#include <unordered_map>
#include <vector>
using namespace std;
/*
dp 实在是太牛逼了，感觉就是随心所欲一般

我们需要求一个最长的subsrtr，条件是满足每个元素之间的差值为diff
现在我们定义一个方程，就是dp[i] 它表示，以值为i结尾的符合上述条件的substr的长度

这样我们就可以写出方程
dp[i] = dp[i- diff] + 1
这里有一个技巧，就是u_m<int, int>没找到就return 0
*/
class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int ans = 0;
        unordered_map<int, int> dp;
        for (int v: arr) {
            dp[v] = dp[v - difference] + 1;
            ans = max(ans, dp[v]);
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}
