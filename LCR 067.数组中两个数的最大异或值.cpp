#include <algorithm>
#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 067 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 067] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution {
public:
    struct Node{
        unordered_map<int, Node*> next;
    };
    Node *root = new Node();
    
    int findMaximumXOR(vector<int>& nums) {
        auto insert = [&](int x){
            Node *cur = root;
            for(int i = 30;i >=0 ;i--){
                int bit = (x >> i) & 1;
                auto it = cur->next.find(bit);
                if(it == cur->next.end()) {
                    cur->next.emplace(bit,new Node());
                }
                cur = cur->next[bit];
            }
        };
        auto query = [&](int x){
            Node *cur = root;
            int res = 0;
            for(int i = 30;i >=0;i--){
                int bit = (x >> i) & 1;
                int want = bit ^ 1;
                auto it = cur->next.find(want);
                if(it == cur->next.end()){
                    cur = cur->next[bit];
                }else{
                    res |= (1 << i);
                    cur = cur->next[want];
                }
            }
            return res;
        };
        int ans = 0;
        insert(nums[0]);
        for (int i = 1; i < (int)nums.size(); ++i) {
            ans = max(ans, query(nums[i]));
            insert(nums[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,10,5,25,2,8]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

// @lcpr case=start
// [8,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [14,70,53,83,49,91,36,80,92,51,66,70]\n
// @lcpr case=end

 */

