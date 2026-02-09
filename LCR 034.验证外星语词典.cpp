#include<string>
#include<istream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 034 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 034] 验证外星语词典
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, int> mp;
    bool cmp(string &word1,string word2){
        for(int i = 0;i < min(word1.size(),word2.size());i ++){
            if(mp[word1[i]] < mp[word2[i]]){
                return 1;
            }else if(mp[word1[i]] > mp[word2[i]]){
                return 0;
            }
        }
        if(word1.size() > word2.size()){
            return 0;
        }
        return 1;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int p = 0;
        for(auto c : order){
            mp[c] = p++;
        }
        string preword = words[0];
        for(int i = 1;i < words.size();i ++){
            if(!cmp(preword, words[i])){
                return 0;
            }
            preword = words[i];
        }
        return 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"\n
// @lcpr case=end

// @lcpr case=start
// ["word","world","row"]\n"worldabcefghijkmnpqstuvxyz"\n
// @lcpr case=end

// @lcpr case=start
// ["apple","app"]\n"abcdefghijklmnopqrstuvwxyz"\n
// @lcpr case=end

 */

