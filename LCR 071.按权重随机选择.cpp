#include <algorithm>
#include <cstdlib>
#include<iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 071 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 071] 按权重随机选择
 */

// @lc code=start
class Solution {
public: 
    vector<long long> pre;
    long long S;
    Solution(vector<int>& w) {
        long long cur = 0;
        for(auto e : w){
            cur += e;
            pre.push_back(cur);
        }
        S= cur;
    }
    
    int pickIndex() {
        long long x = 1+(long long)(rand()%S);
        int idx = (int)(lower_bound(pre.begin(),pre.end(),x)-pre.begin());
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end



/*
// @lcpr case=start
// ["Solution","pickIndex"]\n[[[1]],[]]\n["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]\n[[[1,3]],[],[],[],[],[]]\n
// @lcpr case=end

 */

