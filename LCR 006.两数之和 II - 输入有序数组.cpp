#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=LCR 006 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 006] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i = 0;i < numbers.size();i ++){
            if(mp.count(target - numbers[i])){
                return {mp[target - numbers[i]],i};
            }
            mp[numbers[i]] = i;
        }
        return {0,0};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4,6,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */

