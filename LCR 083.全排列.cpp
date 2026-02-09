#include<iostream>
#include <unordered_map>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 083 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 083] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    int vis[100];
    void dfs(vector<int> &nums,vector<int> &cur){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(vis[i]) continue;
            cur.push_back(nums[i]);
            vis[i] = 1;
            dfs(nums, cur);
            vis[i] = 0;
            cur.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        dfs(nums,cur);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

