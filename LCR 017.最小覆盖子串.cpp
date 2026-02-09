#include <algorithm>
#include <climits>
#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 017 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 017] 最小覆盖子串
 */

// @lc code=start
    class Solution {
    public:
        string minWindow(string s, string t) {
            if(t.empty() || s.empty() || t.size() > s.size()) {
                    return "";
            }
            vector<int> need(128,0),wind(128,0); 
            int required = 0;
            for(auto c : t) {
                if(need[c] == 0) required ++;
                need[c] ++;
            }     
            int formed = 0;
            int res = INT_MAX,bestl = 0;
            int l = 0;
            for(int r = 0;r < s.size();r++){
                char c = s[r];
                wind[c] ++;
                if(need[c] > 0 && wind[c] == need[c]){
                    formed ++;
                }
                while (formed == required) {
                    if(r - l +1 <res ){
                        res = r - l + 1;
                        bestl = l;
                    }
                    char leftChar = s[l];
                    wind[leftChar] --;
                    if(need[leftChar] > 0&&wind[leftChar] < need[leftChar]){
                        formed --;
                    }
                    l++;
                }
            }
            return res == INT_MAX ? "" : s.substr(bestl, res);

        }
    };
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

