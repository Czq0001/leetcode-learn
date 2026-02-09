#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 011 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 011] 连续数组
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0,sum = 0;
        unordered_map<int,int> mp;
        vector<int> psum;
        psum.push_back(0);
        for(auto e:nums){
            sum += (e == 1?1:-1);
            psum.push_back(sum);
        }
        for(int i = 0;i < psum.size();i++){
            if(mp.count(-1 * psum[i])){
                res = max(res,i - mp[-1*psum[i]]);
            }else mp[psum[i]] = i;
        }
        return res;
    }   
};
// @lc code=end



/*
// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

 */

