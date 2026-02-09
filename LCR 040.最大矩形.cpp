#include<iostream>
#include <stack>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 040 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 040] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maxlargearea(vector<int> &h){
        h.push_back(0);
        stack<int> stk;
        int res = 0;
        for(int i = 0;i < h.size();i ++){
            while(!stk.empty() && h[stk.top()] > h[i]){
                int curh = h[stk.top()];
                int right = i;
                stk.pop();
                int left = stk.empty()?-1:stk.top();
                res = max(res,curh*(right - left - 1));
            }
            stk.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<string>& matrix) {
        int ans = 0;
        int m = matrix.size();
        if(m == 0){
            return 0;
        }
        int n = matrix[0].size();
        vector<int> heights(n,0);
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }else{
                    heights[j] = 0;
                }
            }
            ans = max(maxlargearea(heights),ans);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["10100","10111","11111","10010"]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// ["0"]\n
// @lcpr case=end

// @lcpr case=start
// ["1"]\n
// @lcpr case=end

// @lcpr case=start
// ["00"]\n
// @lcpr case=end

 */

