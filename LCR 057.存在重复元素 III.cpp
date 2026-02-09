#include <algorithm>
#include <cstdlib>
#include<iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 057 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 057] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> st;
        if(k <= 0 || t < 0) return false;
        for(int i = 0;i < nums.size();i ++){
            long long x = nums[i];
            auto it = st.lower_bound(x-t);
            if(it!=st.end() && *it <= x+t){
                return true;
            }
            st.insert(x);
            if(i >=k){
                long long y = nums[i-k];
                auto it = st.find(y);
                if(it!=st.end()) st.erase(it); 
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n3\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n2\n
// @lcpr case=end

 */

