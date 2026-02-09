#include<iostream>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 062 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 062] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    /** Initialize your data structure here. */
    struct Node{
        bool isend = false;
        unordered_map<char, Node*> next;
    };
    Node *root;
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur = root;
        for(char c : word){
            auto it = cur->next.find(c);
            if(it!=cur->next.end()){
                cur = it->second;
            }else{
                Node *nn = new Node();
                cur->next.emplace(c,nn);
                cur = nn;
            }
        }
        cur ->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        const Node *node = walk(word);
        return node != nullptr && node->isend;
    }
    const Node*walk(const string &s) const {
        const Node *cur = root;
        for(char c:s){
            auto it = cur->next.find(c);
            if(it == cur->next.end()) return nullptr;
            cur = it->second;
        }
        return cur;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return walk(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end



/*
// @lcpr case=start
// ["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]\n
// @lcpr case=end

 */

