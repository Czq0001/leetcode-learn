#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 081 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 081] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &candidates,int target,vector<int> &cur,int cursum,int idx){
        if(target == cursum){
            res.push_back(cur);
            return;
        }
        if(cursum > target) return;
        for(int i = idx;i < candidates.size();i++){
            cursum += candidates[i];
            cur.push_back(candidates[i]);
            dfs(candidates, target, cur, cursum, i);
            cursum -= candidates[i];
            cur.pop_back();
        }    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        dfs(candidates, target, cur, 0, 0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

