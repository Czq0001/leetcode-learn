#include <functional>
#include<iostream>
#include <queue>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 076 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 076] 数组中的第 K 个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i =0;i < nums.size();i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            }else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1,5,6,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,1,2,4,5,5,6]\n4\n
// @lcpr case=end

 */

