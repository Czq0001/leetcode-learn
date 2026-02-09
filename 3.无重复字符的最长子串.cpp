#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, int> mp;
    int lengthOfLongestSubstring(string s) {
        int l,r;
        l = r =0;
        int res = 0;
        while (r < s.size()) {
            if(mp[s[r]] == 0){
                mp[s[r]] ++;
                r++;
                res = max(r -l ,res);
            }else{
                mp[s[l]] --;
                l++;
            }
        }
        return res;
    }
};

int main() {
  Solution solution;
  cout << solution.lengthOfLongestSubstring("abcbcade") << endl;
  return 0;
}