#include <algorithm>
#include <cmath>
#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 073 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 073] 爱吃香蕉的狒狒
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int l = piles[0];
        int r = *piles.end();
        while(l <= r){
            int mid = l + (r-l)/2;
            int res = 0;
            for(auto e : piles){
                res += ceil(1.0*e/mid);
                if(res > h) break;
            }
            if(res > h){
                l = mid + 1;
            }else if(res < h){
                r = mid-1;
            }else{
                return mid;
            }
        }
        return r;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

 */

