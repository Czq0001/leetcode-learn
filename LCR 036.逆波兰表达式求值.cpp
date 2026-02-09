#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 036 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 036] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> stk;
        for(auto token:tokens){
            if(token == "+"){
                auto p1 = stk.top();
                stk.pop();
                auto p2 = stk.top();
                stk.pop();
                res += p1+p2;
            }else if(token == "-"){
                auto p1 = stk.top();
                stk.pop();
                auto p2 = stk.top();
                stk.pop();
                res += p2-p1;
            }else if(token == "*"){
                auto p1 = stk.top();
                stk.pop();
                auto p2 = stk.top();
                stk.pop();
                res += p2*p1;
            }else if(token == "/"){
                auto p1 = stk.top();
                stk.pop();
                auto p2 = stk.top();
                stk.pop();
                res += p2/p1;
            }else{
                int curp = 1;
                int cursum = 0;
                for(auto c : token){
                    if(c == '-'){
                        curp = -1;
                    }else{
                        cursum = cursum * 10 + c - '0';
                    }
                }
                stk.push(curp * cursum);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */

