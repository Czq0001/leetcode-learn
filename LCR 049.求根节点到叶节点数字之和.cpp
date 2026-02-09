#include<iostream>
#include <queue>
using namespace std;

/*
 * @lc app=leetcode.cn id=LCR 049 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 049] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        stack<pair<TreeNode*,int>> stk;
        int res = 0;
        stk.push({root,0});
        while(!stk.empty()){
            auto [node,cur] = stk.top();
            stk.pop();
            cur = cur*10 + node->val;
            if(!node->left && !node->right){
                res += cur;
            }else{
                if(node->left) stk.push({node->left,cur});
                if(node->right) stk.push({node->right,cur});
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,0,5,1]\n
// @lcpr case=end

 */

