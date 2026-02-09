
#include<iostream>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 054 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 054] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        TreeNode *res = root;
        stack<TreeNode*> stk;
        int sum = 0;
        while(root || !stk.empty()){
            while (root) {
                stk.push(root);
                root = root->right;
            }
            root = stk.top();
            stk.pop();
            int tmp = root->val;
            root->val += sum;
            sum += tmp;
            root = root->left;
        }
        return res;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n
// @lcpr case=end

// @lcpr case=start
// [0,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4,1]\n
// @lcpr case=end

 */

