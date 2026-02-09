#include "iostream"
#include <algorithm>
#include <iterator>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 019 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 019] 验证回文串 II
 */

// @lc code=start
class Solution {
public:
    bool Check(string s) {
        string p = s;
        reverse(p.begin(), p.end());
        int l = 0,r = 0;
        int flag = -1;
        while(l < s.size() && r < s.size()){
            if(~flag&&l == s.size() - flag - 1){
                l ++;
                continue;
            }
            if( ~flag && s[l] != p[r]){
                return false;
            }else if(s[l] != p[r]){
                flag = r;
                r++;
            }else{
                l ++,r++;
            }
            
        }
        return true;
    }
    bool validPalindrome(string s) {
        bool res = true;
        res = Check(s);
        reverse(s.begin(),s.end());
        if(res == false) res = Check(s);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

