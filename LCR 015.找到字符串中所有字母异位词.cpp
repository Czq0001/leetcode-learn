#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 015 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 015] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        findAnagrams(p, s);
        int m = s.size(),n = p.size();
        vector<int>res;
        vector<int>need(26,0),wind(26,0);
        for(auto c : s) need[c-'a'] ++;
        for (int i = 0; i < n; i++) {
            wind[p[i] - 'a'] ++;
            if(i >= m) wind[p[i-m]-'a'] --;
            if(i >= m-1 && wind == need){
                res.push_back(i-m+1);
            } 
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

 */

