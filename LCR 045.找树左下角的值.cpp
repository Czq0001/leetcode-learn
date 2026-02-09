#include<iostream>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 045 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 045] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int res = 0;
        int maxheight = 0;
        q.push({root,1});
        while (!q.empty()) {
            auto [node,height] = q.front();
            q.pop();
            if(height > maxheight){
                res = node->val;
                maxheight = height;
            }
            if(node->left){
                q.push({node->left,height+1});
            }
            if(node->right){
                q.push({node->right,height+1});
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,5,6,null,null,7]\n
// @lcpr case=end

 */

