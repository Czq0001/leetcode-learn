#include <algorithm>
#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 075 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 075] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        auto Cmp = [&](int a,int b){
            return mp[a]<mp[b];
        };
        for(int i = 0;i < arr2.size();i++){
            mp[arr2[i]] = i;
        }
        vector<int> res1;
        vector<int> res2;
        for(int i =0 ;i < arr1.size();i ++){
            if(mp.count(arr1[i])) res1.push_back(arr1[i]);
            else{
                res2.push_back(arr1[i]);
            }
        }
        sort(res1.begin(),res1.end(),Cmp);
        sort(res2.begin(),res2.end());
        for(auto c:res2){
            res1.push_back(c);
        }
        return res1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]\n
// @lcpr case=end

 */

