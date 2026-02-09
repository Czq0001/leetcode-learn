#include<iostream>
#include<vector>
using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=LCR 007 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 007] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = nums.size()-1;i >=2;i --){
            if(i != nums.size()-1 && nums[i] == nums[i+1]) {
                continue;
            }
            int l = 0;
            int r = i-1;
            while(l < r) {
                if(nums[l] + nums[r] + nums[i] == 0){
                    res.push_back({nums[l],nums[r],nums[i]});
                    while( l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l ++;r--;
                }
                if(nums[l] + nums[r] + nums[i] > 0){
                    while(l < r && nums[r] == nums[r-1]) r--;
                    r--;
                }else{
                    while( l < r && nums[l] == nums[l+1]) l++;
                    l ++;
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

