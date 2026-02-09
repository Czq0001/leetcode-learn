#include<iostream>
using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:

    bool isValid(string s) {
        if(s.size() == 1){
            return 0;
        }    
        stack<char> stk;
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '['){
                stk.push(c);
            }
            if(c == ')'){
                if(stk.empty() || stk.top() != '('){
                    return 0;
                }else{
                    stk.pop();
                }
            }
            if(c == '}'){
                if(stk.empty() || stk.top() != '{'){
                    return 0;
                }else{
                    stk.pop();
                }
            }
            if(c == ']'){
                if(stk.empty() || stk.top() != '['){
                    return 0;
                }else{
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};
// @lc code=end

