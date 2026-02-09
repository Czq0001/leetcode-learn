#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int l,r;
        for(int i = 0;i < nums.size()-1;i ++){
            if(i && nums[i] == nums[i-1]) continue;
            int l , r;
            l = i + 1,r = nums.size()-1;
            while(l < r){
                if(nums[l] + nums[r] + nums[i] == 0){
                    ans.push_back({nums[l],nums[i],nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l ++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                    l ++,r--;
                }else{
                    if(nums[l] + nums[r] + nums[i] < 0){
                        while(l < r && nums[l] == nums[l+1]) l ++;
                        l++;
                    }else{
                        while(l < r && nums[r] == nums[r+1]) r--;
                        r--;
                    }
                }
            }
        }    
        return ans;
    }
};
// @lc code=end

