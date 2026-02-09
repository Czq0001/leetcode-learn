#include "iostream"
#include <algorithm>
#include<vector>
#include<stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 039 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 039] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> stk;
        int res = 0;
        for(int i = 0;i < heights.size();i ++){
            int curh = heights[i];
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int right = i;
                int h = heights[stk.top()];
                stk.pop();
                int left = stk.empty()?-1:stk.top();
                res = max(res,(right-left+1) * h);
            }
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

 */

