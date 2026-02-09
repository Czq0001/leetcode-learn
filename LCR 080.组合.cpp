#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 080 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 080] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void dfs(int curk,int k,int idx,int n,vector<int> cur){
        if(curk == k) res.push_back(cur);
        if(curk >= k) return;
        for(int i = idx;i <= n;i++){
            cur.push_back(i);
            dfs(curk+1, k, i+1, n, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        dfs(0, k, 1, n, cur);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

