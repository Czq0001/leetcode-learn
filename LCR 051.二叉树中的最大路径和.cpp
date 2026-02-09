#include <algorithm>
#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 051 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 051] 二叉树中的最大路径和
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
    int ans = -0x3f3f3f3f;
    int dfs(TreeNode *root,int cursum){
        if(!root) return 0;
        int left = dfs(root->left, cursum);
        int right = dfs(root->right, cursum);
        ans = max({ans,root->val+left+right,root->val+left,root->val+right,root->val});
        return max({root->val+left,root->val+right,root->val});
    }
    int maxPathSum(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */

