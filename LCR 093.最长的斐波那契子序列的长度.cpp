#include <algorithm>
#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 093 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 093] 最长的斐波那契子序列的长度
 */

// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> pre;
        for(int i = 0;i < arr.size();i ++){
            pre[arr[i]] = i;
        }
        int n = arr.size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(n,2));
        for(int k = 0;k < n;k ++){
            for(int j = 0;j<k;j++){
                int need = arr[k]-arr[j];
                if(need >= arr[j]) continue;
                if(pre.count(need)&&pre[need] < j){
                    int i = pre[need];
                    dp[j][k] = dp[i][j] +1;
                    ans = max({ans,dp[j][k]});
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8]\n
// @lcpr case=end

 */

