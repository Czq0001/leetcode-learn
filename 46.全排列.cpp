#include<iostream>
#include<vector>
using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    int vis[20];
    void dfs(vector<int>&nums,vector<int> &res){
        if(res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }
        for(int i =0 ;i < nums.size();i ++) {
            if(vis[i]) continue;
            vis[i] = 1;
            res.push_back(nums[i]);
            dfs(nums,res);
            vis[i] = 0;
            res.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        dfs(nums,res);
        return ans;
    }
};
// @lc code=end

