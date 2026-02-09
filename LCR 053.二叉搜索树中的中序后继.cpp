#include<iostream>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 053 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 053] 二叉搜索树中的中序后继
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*>st;
        int flag = 0;
        while (root || !st.empty()) {
            while (root) {
                if(flag){
                    return root;
                }
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(flag){
                return root;
            }
            if(root == p){
                flag = 1;
            }
            root = root->right;
        }
        return nullptr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n1\n
// @lcpr case=end

 */

