#include<iostream>
#include<vector>
using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = 0x3f3f3f3f;
        int maxp = -0x3f3f3f3f;
        
        for(int i = 0 ;i < prices.size();i ++) {
            if(prices[i] < minp){
                minp = prices[i];
            }else{
                maxp = max(prices[i] - minp,maxp);
            }
        }
        return max(maxp,0);

    }
};
// @lc code=end

