#include <algorithm>
#include <cstddef>
#include <cstring>
#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 094 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 094] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    bool isPal[2001][2001];
    int dp[2001];
    int minCut(string s) {
        int n = s.size();
        if(s.size()==1) return 0;
        
        for(int len =1;len <= s.size();len++){
            for(int i = 0;i+len-1<s.size();i++){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    if(j-i+1 <=2) isPal[i][j] = 1;
                    else isPal[i][j] = isPal[i+1][j-1];
                }
            }
        }
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0;i < n ;i ++){
            if(isPal[0][i]){
                dp[i] = 0;
                continue;
            }
            for(int j = 1;j <=i;j ++){
                if(isPal[j][i]){
                    dp[i] = min(dp[i],dp[j-1]+1);
                }
            }
        }
        return dp[n-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n
// @lcpr case=end

 */

