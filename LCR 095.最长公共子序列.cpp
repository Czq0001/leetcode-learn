#include <algorithm>
#include <cstddef>
#include <cstring>
#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 095 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 095] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        memset(dp, -0x3f, sizeof(dp));
        for(int i =0 ;i < len1;i ++) dp[i+1][0] = 0;
        for(int i =0 ;i < len2;i ++) dp[0][i+1] = 0;
        dp[0][0] = 0;
        for(int i = 0;i < len1;i ++){
            for(int j =0;j<len2;j++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = max(dp[i][j] + 1,dp[i+1][j+1]);
                }else{
                    dp[i+1][j+1] = max({dp[i][j+1],dp[i+1][j]});
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */

