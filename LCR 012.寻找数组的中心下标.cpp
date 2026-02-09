#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 012 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 012] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> psum;
        psum.push_back(0);
        int sum = 0;
        for(auto e : nums){
            sum += e;
            psum.push_back(sum);
        }
        psum.push_back(sum);
        for(int i = 1;i < psum.size()-1;i++){
            if(psum[psum.size()-1]-psum[i] == psum[i-1]-psum[0]){
                return i-1;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,3,6,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,-1]\n
// @lcpr case=end

 */

