#include <exception>
#include<iostream>
#include <utility>
#include<vector>
#include<stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 038 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 038] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        vector<int> vt(0,temperatures.size());
        for(int i = 0;i < temperatures.size();i ++){
            while(!stk.empty() && stk.top().first < temperatures[i]){
                vt[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push({temperatures[i],i});
        }
        return vt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */

