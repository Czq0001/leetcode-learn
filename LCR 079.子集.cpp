#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 079 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 079] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &res,int idx,vector<int> &nums ){
        for(int i = idx;i < nums.size();i++){
            res.push_back(nums[i]);
            ans.push_back(res);
            dfs(res, i+1, nums);
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        ans.push_back(res);
        dfs(res, 0,nums);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

