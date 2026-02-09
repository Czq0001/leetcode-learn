#include <algorithm>
#include <cstddef>
#include <cstring>
#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 092 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 092] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution {
public:
    int dp[20002][2];
    int minFlipsMonoIncr(string s) {
        s = "0" + s;
        memset(dp, 0x3f, sizeof(dp));
        if(s[0] == '0') dp[0][0] = 0;
        else dp[0][1] = 0;
        for(int i = 1;i < s.size();i ++){
            if(s[i] < s[i-1]){
                dp[i][1] = min({dp[i-1][0]+1,dp[i-1][1] + 1});
                dp[i][0] = min({dp[i-1][0]});
            }else if(s[i] > s[i-1]){
                dp[i][1] = min({dp[i-1][0],dp[i-1][1]});
                dp[i][0] = dp[i-1][0]+1;
            }else{
                if(s[i] == '0'){
                    dp[i][1] = min({dp[i-1][0],dp[i-1][1]})+1;
                    dp[i][0] = dp[i-1][0];
                }else{
                    dp[i][1] = min({dp[i-1][1],dp[i-1][0]});
                    dp[i][0] = dp[i-1][0]+1;
                }
            }
        }
        return min(dp[s.size()-1][0],dp[s.size()-1][1]);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "00110"\n
// @lcpr case=end

// @lcpr case=start
// "010110"\n
// @lcpr case=end

// @lcpr case=start
// "00011000"\n
// @lcpr case=end

 */

