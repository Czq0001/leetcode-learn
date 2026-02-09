#include <functional>
#include<iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 059 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 059] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_map<int,int> mp;
    int gk = 0;
    KthLargest(int k, vector<int>& nums) {
        gk = k;
        for(auto num : nums){
            
            mp[num] = 1;
            if(pq.size() < k){
                pq.push(num);
            }else{
                if(pq.top() < num){
                    pq.pop();
                    pq.push(num);
                }
            }
            
        }
    }
    
    int add(int val) {
        
        mp[val] = 1;
        if(pq.size() < gk){
            pq.push(val);
        }else{
            if(pq.top() < val){
                pq.pop();
                pq.push(val);
            }
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end



/*
// @lcpr case=start
// ["KthLargest","add","add","add","add","add"]\n[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]\n
// @lcpr case=end

 */

