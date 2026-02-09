
#include <unordered_map>
#include <vector>
using namespace std;
int main() { return 0; }
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
  unordered_map<int, vector<int>> mp1;
  unordered_map<int, int> mp2;
  vector<int> twoSum(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      mp1[nums[i]].push_back(i);
    }
    vector<int> res;
    for (auto n : nums) {
      if (mp1.count(target - n)) {
        if (target - n == n) {
          if (mp1[n].size() > 1) {
            res.push_back(mp1[n][0]);
            res.push_back(mp1[n][1]);
            return res;
          }
        } else {
          res.push_back(mp1[n][0]);
          res.push_back(mp1[target - n][0]);
          return res;
        }
      }
    }
    return res;
  }
};
// @lc code=end
