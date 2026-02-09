#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 089 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 089] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max({nums[0],nums[1]});
        vector<int> res(0,nums.size()+1);
        res[0] = nums[0];
        res[1] = nums[1];
        for(int i = 2;i < nums.size();i++){
            res[i] = max({res[i-2] + nums[i],res[i-1]});
        }
        return res[nums.size()-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */

