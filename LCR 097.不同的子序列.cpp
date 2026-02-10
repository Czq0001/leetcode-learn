#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 097 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 097] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int dp[1001][1001];
    int numDistinct(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        for(int i =1;i <=len1;i++){
            dp[0][i] = 1;
        }
        for(int i =1;i <=len2;i++){
            dp[i][0] = 0;
        }
        dp[0][0] = 1;
        for(int i = 1;i <= len1;i++){
            for(int j =1;j <= len2;j++){
                if(s[i-1] == t[j-1]){
                    dp[j][i] = dp[j-1][i-1] + dp[j][i-1];
                }else{
                    dp[j][i] = dp[j][i-1];
                }
            }
        }
        return dp[len2][len1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "rabbbit"\n"rabbit"\n
// @lcpr case=end

// @lcpr case=start
// "babgbag"\n"bag"\n
// @lcpr case=end

 */

