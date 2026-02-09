#include<iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 086 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 086] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    int dp[20][20];
    void dfs(vector<string> curres,int k,string &s){
        if(k == s.size()) {
            res.push_back(curres);
            return;
        }
        for(int i = k;i < s.size();i++){
            if(!dp[k][i]) continue;
            curres.push_back(s.substr(k,i-k+1));
            dfs(curres, i+1, s);
            curres.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        for(int len = 1;len <= s.size();len++){
            for(int i = 0;i+len-1<s.size();i++){
                int j = i+len -1;
                if(s[i] != s[j]) continue;
                if(len <=2) dp[i][j] = true;
                else dp[i][j] = dp[i+1][j-1];
            }
        }
        vector<string> curres;
        dfs(curres, 0, s);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "google"\n
// @lcpr case=end

// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

