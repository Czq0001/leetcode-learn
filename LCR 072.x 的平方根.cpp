#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 072 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 072] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 1,r = x/2;
        while(l <= r){
            long long mid = l + (r-l)/2;
            if(mid *mid == x){
                return mid;
            }else if(mid * mid > x){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */

