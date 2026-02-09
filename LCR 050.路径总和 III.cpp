#include<iostream>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 050 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 050] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    unordered_map<int, int> mp;
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return dfs(root, 0, targetSum);
    }
    int dfs(TreeNode* node,int cursum,int target){
        if(!node) return 0;
        cursum += node->val;
        int res = 0;
        auto it = mp.find(cursum - target);
        if(it != mp.end()) res += it->second;
        mp[cursum] ++;
        res += dfs(node->left, cursum, target);
        res += dfs(node->right, cursum, target);
        mp[cursum]--;
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */

