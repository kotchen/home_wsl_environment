#include <vector>
#include <string.h>
using namespace std;
/*
这道题算是我的第一题  图的问题
一开始的思路就是用一个数组进行标记，然后最后判断一下他自己的票是否是n-1
思路是对的，为什么没有他的快呢？
思路：想象一个图，如果有法官，那么被人都指向他，并且他自己不指向别人
因为这里每一个人都只能指向一个人，并且不是自己，所以，路径可以被抵消

这里从出度和入度来思考，
别人认为你是judge，那么你的入度+1, 如果你认为别人是
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //入度数组
        vector<int> inDegree(n,0);
        for(vector<int>& tru:trust){
            inDegree[tru[1]-1]++;
            inDegree[tru[0]-1]--;
        }

        int result = -1;
        for(int i = 0;i<n;i++){
            if(inDegree[i] == n-1 ) result = i+1;
        }
        return result;
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n==1 && trust.empty()) return 1;
        int* poll = new int[n];
        memset(poll, 0, n*sizeof(int));
        for (auto i : trust)
        {
            poll[i[0]-1]--;
            poll[i[1]-1]++; 
        }
        for (int i = 0; i<n; i++)
        {
            if  ((poll[i]==n-1)) 
                return i+1;
        }
        return -1;
    }    
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
