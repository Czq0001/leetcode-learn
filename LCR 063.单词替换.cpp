#include <algorithm>
#include<iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 063 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 063] 单词替换
 */

// @lc code=start
class Solution {
public:
    // struct Cmp{
    //     bool operator()(const string &a,const string &b) const {
    //         return a.size() > b.size();
    //     }
    // };
    // static bool Cmp(string &a,string &b) {
    //         return a.size() > b.size();
    // }
    vector<string> split(string &s){
        string cur;
        vector<string> res;
        for(auto c : s){
            if(c == ' '){
                res.push_back(cur);
                cur.clear();
                continue;
            }
            cur += c;
        }
        if(cur.size() > 0){
            res.push_back(cur);
        }
        return res;
    }
    struct Node{
        bool isend = false;
        unordered_map<char, Node*> next; 
    };
    Node *root = new Node();
    bool insert(string &word){
        Node *cur = root;
        for(auto c : word){
            auto it = cur->next.find(c);
            if(it != cur->next.end()){
                cur = it->second;
            }else{
                Node *nn = new Node();
                cur->next.emplace(c,nn);
                cur = nn;
            }
        }
        cur->isend = true;
    }
    int prefix(string &pre){
        Node *cur = root;
        for(int i =0;i < pre.size();i++){
            auto it = cur->next.find(pre[i]);
            if(it == cur->next.end()) return -1;
            if(it->second->isend) return i;
            cur = it->second;
        }
        return -1;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto s:dictionary){
            insert(s);
        }
        string res = "";
        auto vt = split(sentence);
        for(int i = 0;i < vt.size();i++){
            if(res.size() > 0) res+= " ";
            int len = prefix(vt[i]);
            if(~len){
                res += vt[i].substr(0,len+1); 
            }else{
                res += vt[i];
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["cat","bat","rat"]\n"the cattle was rattled by the battery"\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","c"]\n"aadsfasf absbs bbab cadsfafs"\n
// @lcpr case=end

// @lcpr case=start
// ["a", "aa", "aaa", "aaaa"]\n"a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"\n
// @lcpr case=end

// @lcpr case=start
// ["catt","cat","bat","rat"]\n"the cattle was rattled by the battery"\n
// @lcpr case=end

// @lcpr case=start
// ["ac","ab"]\n"it is abnormal that this solution is accepted"\n
// @lcpr case=end

 */

