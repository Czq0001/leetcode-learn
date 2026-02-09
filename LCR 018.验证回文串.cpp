/*
 * @lc app=leetcode.cn id=LCR 018 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 018] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string p = "";
        for(auto c : s){
            if(c <= 'z' && c >= 'a'){
                p += c;
            }else if(c <= 'Z' && c >= 'A'){
                p += 'a' +(c - 'A');
            }else if(c <= '9' && c >= '0') p += c;
        }
        int l =0 ,r = p.size() - 1;
        while (l < r) {
            if(p[l] != p[r]) return false;
            l++,r--;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

 */

