#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=LCR 008 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 008] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> presum;
        int sum,res = 0x3f3f3f3f;
        presum.push_back(0);
        sum = 0;
        for(int i = 0;i <= nums.size()-1;i++){
            sum += nums[i];
            presum.push_back(sum);
        }
        for(int i = 1;i <= presum.size()-1;i ++){
            int t = presum[i]-target;
            int l = 0,r = i-1;
            int ans = -1;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(presum[mid] <= t){
                    l = mid+1;
                    ans = mid;
                }else{
                    r= mid-1;
                }
            }
            if(~ans){
                res = min(res,i-ans);
            }
        }
        return res == 0x3f3f3f3f?0:res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

