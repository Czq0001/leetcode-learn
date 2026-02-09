#include <iostream>
#include <vector>
#include "string"
#include "unordered_map"
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 014 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 014] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(),n = s2.size();
        if(m > n) {
            return false;
        }
        vector<int> need(26,0),wind(26,0);
        for(auto c:s1){
            need[c-'a'] += 1;
        }
        for(int i = 0;i < n;i ++){
            wind[s2[i] - 'a'] ++;
            if(i >= m) wind[s2[i-m]-'a'] --;
            if(i >= m-1 && wind == need) return true;
        }
        return false;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ab"\n"eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"eidboaoo"\n
// @lcpr case=end

 */

