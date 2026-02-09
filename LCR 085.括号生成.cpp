#include<iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 085 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 085] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    void dfs(int curl,int curr,string &s,int n){
        if(s.size() == 2*n && curl == curr){
            res.push_back(s);
        }
        if(s.size() >= 2*n) return;
        if(curl >=curr){
            s += "(";
            dfs(curl+1, curr, s, n);
            s.pop_back();
        }
        if(curr < curl){
            s += ")";
            dfs(curl, curr+1, s, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(0, 0, s, n);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

