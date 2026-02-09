#include <algorithm>
#include<iostream>
#include <unordered_map>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 082 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 082] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    unordered_map<vector<int>, int> vis;
    void dfs(vector<int> &candidates,int &target,int idx,vector<int> &cur,int cursum){
        if(cursum == target){
            if(vis.count(cur)) return;
            vis[cur] = 1;
            res.push_back(cur);
            return;
        }
        if(cursum > target) return;
        for(int i = idx;i < candidates.size();i++){
            cursum += candidates[i];
            cur.push_back(candidates[i]);
            dfs(candidates, target, i+1, cur, cursum);
            cursum -= candidates[i];
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        dfs(candidates, target, 0, cur, 0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */

