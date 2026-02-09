#include<iostream>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 056 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 056] 两数之和 IV - 输入二叉搜索树
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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        unordered_map<int, int> mp;
        while (root||!stk.empty()) {
            while (root) {
                stk.push(root);
                root= root->left;
            }
            root=stk.top();
            stk.pop();
            if(mp.count(k - root->val)) return true;
            mp[root->val] = 1;
            root = root->right;
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,6,10,5,7,9,11]\n12\n
// @lcpr case=end

// @lcpr case=start
// [8,6,10,5,7,9,11]\n22\n
// @lcpr case=end

 */

