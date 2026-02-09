#include<iostream>
#include<vector>

using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
bool cmp(vector<int> &a,vector<int> &b){
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    unordered_map<int,vector<int>>mp;
    vector<int> pos;
    int ztail[100005];
    int cnt =0;
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        for(auto e:envelopes){
            pos.push_back(e[1]);
        }
        for(auto x : pos){
int l = 0 , r= cnt -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if()
        }
        }
        
        return cnt;
    }
};
// @lc code=end