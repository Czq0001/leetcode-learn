#include<iostream>
#include<unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 020 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 020] 回文子串
 */

// @lc code=start
class Solution {
public:
    
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        auto expand = [&] (int l,int r){
            while(l >=0 && r < n && s[l] == s[r]){
                res ++;
                l --,r++;
            }
        };
        for(int i =0;i < n;i ++){
            expand(i, i);
            expand(i, i+1);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n
// @lcpr case=end

 */

