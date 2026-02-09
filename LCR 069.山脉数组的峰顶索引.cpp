#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 069 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 069] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0,r = arr.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(!mid) l = mid + 1;
            else if(mid == arr.size()-1) r = mid-1;
            else if(arr[mid]>arr[mid-1] && arr[mid+1] > arr[mid]) l = mid+1;
            else if(arr[mid] < arr[mid-1] &&arr[mid+1] < arr[mid]) r = mid - 1;
            else{
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,10,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1]\n
// @lcpr case=end

// @lcpr case=start
// [24,69,100,99,79,78,67,36,26,19]\n
// @lcpr case=end

 */

