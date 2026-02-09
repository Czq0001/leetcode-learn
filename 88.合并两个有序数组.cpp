#include<iostream>
#include<vector>
using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        int i = 0, j =0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]){
                tmp.push_back(nums1[i]);
                i++;
            }else{
                tmp.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m) {
            tmp.push_back(nums1[i]);
            i++;
        }
        while(j < n) {
            tmp.push_back(nums2[j]);
            j++;
        }
        for(int i = 0 ;i < m +n ;i ++){
            nums1[i] = tmp[i];
        }
    }
};
// @lc code=end

