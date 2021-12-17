#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
class Solution {
private:
    static const int MAXN = 40004;
    static const int bias = 10001;
    static int lowbit(int x) {
        return x & (-x);
    }
    
    int tree[40004];

    void add(int x, int num) {
        int pos = x;
        while (pos < MAXN) {
            tree[pos] += num;
            pos += lowbit(pos);
        }
    }

    int ask(int pos) {
        int ans = 0;
        while (pos > 0) {
            ans += tree[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }
public:
    Solution() {
        memset(tree, 0, sizeof(tree));
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        if (nums.size() == 0) {
            return ans;
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] = ask(nums[i] + bias - 1);
            add(nums[i] + bias, 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {5, 2, 6, 1};
    for (auto i : s.countSmaller(v))
        std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}