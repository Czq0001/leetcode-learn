#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 074 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 074] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool Cmp(vector<int> a,vector<int> b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),Cmp);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1;i < intervals.size();i++){
            if(res[res.size()-1][1] >= intervals[i][0]){
                res[res.size()-1][1] = max({res[res.size()-1][1],intervals[i][1]});
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

 */

