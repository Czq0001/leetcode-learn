#include "vector"
#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 068 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 068] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l,r;
        l = 0,r = nums.size()-1;
        while(l <= r){
            int mid= l + (r-l)/2;
            if(nums[mid] > target){
                r = mid-1;
            }else if(nums[mid] < target){
                l = mid+1;
            }else{
                return mid;
            }
        }
        return l;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

