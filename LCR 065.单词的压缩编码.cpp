#include <algorithm>
#include<iostream>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 065 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 065] 单词的压缩编码
 */

// @lc code=start
class Solution {
public:
    struct Node {
        bool isend = false;
        unordered_map<char, Node*> next;
    };
    Node *root = new Node();
    int res = 0;
    void insert(string word){
        int flag = 0,pre = -1;
        Node *cur = root;
        for(int i = 0;i < word.size();i ++){
            char c = word[i];
            auto it = cur->next.find(c);
            if(it != cur->next.end()){
                cur = it->second;
            }else{
                flag = 1;
                if(cur->isend){
                    pre = i + 1;
                }
                Node *nn = new Node();
                cur->next.emplace(c,nn);
                cur = nn;
            }
        }
        cur->isend = true;
        if(flag){
            res = res + (word.size());
        }
        if(~pre){
            res -= pre;
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        for(auto word : words){
            reverse(word.begin(), word.end());
            insert(word);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["time","me","bell"]\n
// @lcpr case=end

// @lcpr case=start
// ["t"]\n
// @lcpr case=end

 */

