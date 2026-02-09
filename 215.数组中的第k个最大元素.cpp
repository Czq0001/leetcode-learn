#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() { return 0; }
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto e : nums) {
      if (pq.size() == k) {
        if (pq.top() < e) {
          pq.pop();
          pq.push(e);
        }
      } else {
        pq.push(e);
      }
    }
    return pq.top();
  }
};
// @lc code=end
