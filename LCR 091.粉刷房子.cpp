#include <algorithm>
#include <cstring>
#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 091 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 091] 粉刷房子
 */

// @lc code=start
class Solution {
public:
    int dp[101][4];
    int minCost(vector<vector<int>>& costs) {
        
        memset(dp,0x3f, sizeof(dp));
        dp[0][0] = costs[0][0];dp[0][1] = costs[0][1];dp[0][2] = costs[0][2];
        // dp[1][0] = costs[1][0];dp[0][1] = costs[1][1];dp[0][2] = costs[1][2];
        for(int i =1;i < costs.size();i ++){
            dp[i][0] = min({dp[i-1][1] + costs[i][0],dp[i-1][2]+costs[i][0]});
            dp[i][1] = min({dp[i-1][0] + costs[i][1],dp[i-1][2]+costs[i][1]});
            dp[i][2] = min({dp[i-1][0] + costs[i][2],dp[i-1][1]+costs[i][2]});
        }
        return min({dp[costs.size()-1][0],dp[costs.size()-1][1],dp[costs.size()-1][2]});
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[17,2,17],[16,16,5],[14,3,19]]\n
// @lcpr case=end

// @lcpr case=start
// [[7,6,2]]\n
// @lcpr case=end

 */

