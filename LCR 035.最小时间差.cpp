#include "iostream"
#include <algorithm>
#include<vector>
#include "string"
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 035 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 035] 最小时间差
 */

// @lc code=start
class Solution {
public:
    int Convert(string &s){
        int sum = 0;
        int res = 0;
        for(auto c : s){
            if(c != ':'){
                sum = sum *10 + c- '0';
            }else{
                res = sum * 60;
                sum = 0;
            }
        }
        return res + sum;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> p;
        for(auto point:timePoints){
            p.push_back(Convert(point));
        }
        sort(p.begin(),p.end());
        int ans = 0x3f3f3f3f;
        for(int i = 1;i < p.size();i ++){
            if(p[i] - p[i-1] < ans){
                ans = p[i] - p[i-1];
            }
            if(24 * 60 +(p[i-1] - p[i]) < ans) {
                ans = 24 * 60 +(p[i-1] - p[i]);
            }
        }
        if(24 * 60 + p[0] - p[p.size()-1] < ans){
            ans = 24 * 60 + p[0] - p[p.size()-1];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["23:59","00:00"]\n
// @lcpr case=end

// @lcpr case=start
// ["00:00","23:59","00:00"]\n
// @lcpr case=end

 */

