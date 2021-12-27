#include<vector>
using namespace std;
/*
先说写法，后说优化：


写法：
思路就是
prices[i] - min(prices[0,i-1])
我的思路是对的，其实只要用一个变量记录最小值就好了，不需要每算一天都要找一次最小值

优化：
一开始使用的是if else判断，比较大小，感觉原理是一样的
但是从这里看出，如果是这样的比较逻辑来复制，建议直接使用
std::max
std::min
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest_price = prices[0];
        int max_income = 0;
        for (int i = 1; i<prices.size(); i++)
        {
            // if (prices[i]<lowest_price)
            //     lowest_price = prices[i];
            // if (prices[i]-lowest_price>max_income)
            //     max_income = prices[i]-lowest_price; 
            lowest_price = std::min(lowest_price, prices[i]);
            max_income = std::max(max_income, prices[i]-lowest_price);
        }
        return max_income;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v = {7,1,5,3,6,4};
    s.maxProfit(v);
    return 0;
}
