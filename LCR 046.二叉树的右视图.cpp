#include <iostream>
#include <queue>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 046 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 046] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        vector<int> res;
        if(root == nullptr) return res;
        q.push({root,1});
        while (!q.empty()) {
            auto [node,h] = q.front();
            q.pop();
            if(res.size() < h){
                res.push_back(node->val);
            }
            if(node->right){
                q.push({node->right,h+1});
            }
            if(node->left){
                q.push({node->left,h+1});
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

