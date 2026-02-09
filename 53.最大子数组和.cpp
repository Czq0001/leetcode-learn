#include<iostream>
#include<vector>
using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int ans = -0x3f3f3f3f;
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for(int i = 0;i < nums.size();i++){
            dp[i] = nums[i];
            ans = max(ans,nums[i]);
        }
        for(int i = 1;i < nums.size(); i++){
            dp[i] = max(dp[i-1] + dp[i],dp[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
// @lc code=end

