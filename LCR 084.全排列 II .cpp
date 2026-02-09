#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 084 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 084] 全排列 II 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    int vis[1000];
    void dfs(vector<int> &cur,vector<int> &nums){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(vis[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1]) continue;
            vis[i] = 1;
            cur.push_back(nums[i]);
            dfs(cur, nums);
            cur.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> cur;
        dfs(cur, nums);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

