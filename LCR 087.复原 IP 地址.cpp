#include<iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 087 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 087] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    bool isOk(string s){
        if(s.size() == 1) return true;
        if(s.size() > 1 && s[0] == '0') return false;
        if(s.size() > 3) return false;
        int cur = 0;
        for(auto c : s){
            cur = cur * 10 + c-'0';
        }
        if(cur > 255)return false;
        return true;
    }
    vector<string> res;
    void dfs(string s,int start,vector<string> cur){
        if(cur.size() == 4 && start > s.size()){
            string ans = cur[0];
            for(int i = 1;i < 4;i ++) ans =ans + "."+ cur[i];
            res.push_back(ans);
            return;
        }
        if(start > s.size()) return;

        for(int end = start;end < s.size();end++){
            string p = s.substr(start,end-start+1);
            if(!isOk(p)) return;
            cur.push_back(p);
            dfs(s, end+1, cur);
            cur.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 20) return res;
        vector<string> cur;
        dfs(s, 0, cur);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "1111"\n
// @lcpr case=end

// @lcpr case=start
// "010010"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */

