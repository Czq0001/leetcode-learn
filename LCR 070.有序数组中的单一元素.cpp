#include<iostream>
#include "vector"
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 070 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 070] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l = 0,r = nums.size()-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if(!mid){
                if(nums[mid] == nums[mid+1]){
                    l = mid+1;
                }else{
                    return nums[0];
                }
            }else if(mid == nums.size()-1){
                if(nums[mid] == nums[mid-1]){
                    r = mid-1;
                }else{
                    return nums[mid];
                }
            }else{
                if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                    return nums[mid];
                }else if(nums[mid]!=nums[mid-1]){
                    if(mid %2){
                        r = mid-1;
                    }else{
                        l = mid+1;
                    }
                }else{
                    if(mid%2){
                        l = mid+1;
                    }else{
                        r = mid-1;
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,3,3,4,4,8,8]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,7,7,10,11,11]\n
// @lcpr case=end

 */

