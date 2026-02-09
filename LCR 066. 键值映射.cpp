#include<iostream>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 066 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 066]  键值映射
 */

// @lc code=start
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {

    }
    struct Node {
        int val = 0;
        bool isend = false;
        unordered_map<char, Node*> next;
    };
    unordered_map<string, int> mp;
    Node *root = new Node();
    void insert(string word,int key){
        int flag = 0;
        if(mp.count(word)){
            flag = 1;
        }
        Node *cur = root;
        for(int i = 0;i < word.size();i ++){
            char c = word[i];
            auto it = cur->next.find(c);
            if(it != cur->next.end()){
                cur = it->second;
                if(flag) cur->val -= mp[word];
                cur->val += key;
            }else{
                Node *nn = new Node();
                cur->next.emplace(c,nn);
                nn->val += key;
                cur = nn;
            }
        }
        cur->isend = true;
        mp[word] = key;
    }
    
    int sum(string prefix) {
        Node *cur = root;
        int res = 0;
        for(auto c : prefix){
            auto it = cur->next.find(c);
            if(it == cur->next.end()){
                return 0;
            }
            cur = it->second;
            res = cur->val;
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MapSum", "insert", "sum", "insert", "sum"]\n[[], ["apple",3], ["ap"], ["app",2], ["ap"]]\n
// @lcpr case=end

 */

