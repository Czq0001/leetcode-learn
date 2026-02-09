
#include <functional>
#include<iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 061 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 061] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution {
public:
    struct Cmp{ 
        bool operator()(const pair<int,int> &a,const pair<int,int> &b)const{
            return (a.first + a.second) < (b.first+b.second);
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int, int>>,Cmp> pq;
        vector<vector<int>> res;
        for(auto num1:nums1){
            for(auto num2:nums2){
                if(pq.size()<k){
                    pq.push({num1,num2});
                }else{
                    if((num2+num1) < (pq.top().first+pq.top().second)){
                        pq.pop();
                        pq.push({num1,num2});
                    }else{
                        break;
                    }
                }
            }
        }
        while (!pq.empty()) {
            res.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3]\n3\n
// @lcpr case=end

 */

