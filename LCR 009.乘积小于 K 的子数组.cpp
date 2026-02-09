#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    return 0;   
}
/*
 * @lc app=leetcode.cn id=LCR 009 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 009] 乘积小于 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int mul = 1;
        int l = 0,r = 0;
        while(r < nums.size()){
            mul *= nums[r];
            if(mul >= k){
                while (l<=r) {
                    mul /= nums[l];
                    if(mul < k) break;
                    l ++;
                }
            }
            res += r - l + 1;
            r++;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,2,6]\n100\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n0\n
// @lcpr case=end

 */

