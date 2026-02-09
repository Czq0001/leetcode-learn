#include<iostream>
#include<deque>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 037 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 037] 行星碰撞
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> vt;
        for(auto e : asteroids){
            if(vt.empty() || e > 0 || vt.back() < 0){
                vt.push_back(e);
            }else{
                while(!vt.empty() || (vt.back() > 0&&-1 * e > vt.back())){
                    vt.pop_back();
                }
                if(vt.empty() || vt.back() < 0){
                    vt.push_back(e);
                }else if(-1 * e == vt.back()){
                    vt.pop_back();
                }
            }
        }
        return vt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,10,-5]\n
// @lcpr case=end

// @lcpr case=start
// [8,-8]\n
// @lcpr case=end

// @lcpr case=start
// [10,2,-5]\n
// @lcpr case=end

// @lcpr case=start
// [-2,-1,1,2]\n
// @lcpr case=end

 */

