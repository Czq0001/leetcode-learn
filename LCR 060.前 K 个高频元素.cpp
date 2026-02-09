#include <functional>
#include<iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 060 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 060] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    //小根队优先
    struct Cmp{
        bool operator()(const pair<int,int>&a,pair<int,int>&b) const {
            return a.second > b.second;
        }
    };
    unordered_map<int, int> mp;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> pq;
        vector<int> res;
        for(auto num:nums){
            mp[num] ++;
        }
        for(auto it:mp){
            if(pq.size()<k){
                pq.push({it.first,it.second});
            }else{
                if(it.second > pq.top().second){
                    pq.pop();
                    pq.push({it.first,it.second});
                }
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

