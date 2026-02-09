#include<iostream>
using namespace std;
/*
@lc app=leetcode.cn id=LCR 047 lang=cpp
@lcpr version=30307
 *
[LCR 047] 二叉树剪枝
 */

// @lc code=start
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
    int Delete(TreeNode* root){
        if(root == nullptr) { 
            return 0;
        }
        int p1= 0;
        if(root->left){
            p1 = Delete(root->left);
        }
        if(p1 == 0){
            root->left = nullptr;
        }
        int p2 = 0;
        if(root->right){
            p2 = Delete(root->right);
        }
        if(p2 == 0){
            root->right = nullptr;
        }
        return max({root->val,p1,p2});
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode *newroot = new TreeNode(1);
        newroot -> left = root;
        Delete(newroot);
        return newroot->left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,0,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,0,0,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,1,1,0,1,0]\n
// @lcpr case=end

 */

