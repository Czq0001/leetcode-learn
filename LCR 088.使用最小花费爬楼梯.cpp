#include<iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 088 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 088] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2) return min({cost[0],cost[1]});
        vector<int> dp(0x3f3f3f,cost.size()+1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i =2;i<=cost.size();i++){
            dp[i] = min({dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]});
        }
        return dp[cost.size()];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

 */

