#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 096 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 096] 交错字符串
 */

// @lc code=start
class Solution {
public:
    int dp[101][101];
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        for(int i =1;i<=len1;i++){
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        for(int i =1;i<=len2;i++){
            dp[0][i] = dp[0][i-1] && (s2[i-1] == s3[i-1]);
        }
        dp[0][0] = true;
        for(int i =1;i<=len1;i++){
            for(int j = 1;j <= len2;j++){
                dp[i][j] = (dp[i-1][j] &&(s1[i-1] == s3[i+j-1])) || (dp[i][j-1] &&(s2[j-1] == s3[i+j-1]));
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbcbcac"\n
// @lcpr case=end

// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbbaccc"\n
// @lcpr case=end

// @lcpr case=start
// ""\n""\n""\n
// @lcpr case=end

 */

