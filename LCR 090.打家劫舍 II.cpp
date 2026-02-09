#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 090 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 090] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int robline(vector<int> &nums,int l,int r){
        int pre1 = 0;
        int pre2 = 0;
        for(int i = l;i <=r;i++){
            int cur = max(pre1,pre2 + nums[i]);
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        return max({robline(nums, 0, nums.size()-2),robline(nums, 1, nums.size()-1)});
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

 */

