#include<vector>
#include<unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 010 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 010] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> presum;
        unordered_map<int, int> mp;
        int sum =0;
        presum.push_back(0);
        for(auto e:nums){
            sum += e;
            presum.push_back(sum);
        }
        int res = 0;
        for(int i = 0;i < presum.size();i++){
            if(mp.count(k - nums[i])){
                res ++;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */

