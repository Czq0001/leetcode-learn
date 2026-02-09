#include<iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 064 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 064] 实现一个魔法字典
 */

// @lc code=start
class MagicDictionary {
public:
    unordered_map<string, int> patternCount;
    unordered_set<string> dict;
    /** Initialize your data structure here. */
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        patternCount.clear();
        dict.clear();

        for(auto w : dictionary){
            dict.insert(w);
            string p = w;
            for(int i = 0;i < p.size();i++){
                p[i] = '*';
                ++patternCount[p];
                p[i]= w[i];
            }
        }
    }
    
    bool search(string searchWord) {
        bool isDict = dict.count(searchWord) > 0;
        string p = searchWord;

        for(int i = 0;i<searchWord.size();i++){
            char old = p[i];
            p[i] = '*';
            auto it = patternCount.find(p);
            if(it != patternCount.end()){
                if(!isDict) return true;
                if(it->second >= 2) return true;
            }
            p[i] = old;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MagicDictionary", "buildDict", "search", "search", "search", "search"]\n[[], [["hello","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]\n
// @lcpr case=end

 */

