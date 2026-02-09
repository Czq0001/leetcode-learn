#include<iostream>
#include<queue>
using namespace std;
/*
@lc app=leetcode.cn id=LCR 044 lang=cpp
@lcpr version=30307
 *
[LCR 044] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;

        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while (!q.empty()) {
            auto [node,height] = q.front();
            q.pop();
            if(res.size() < height){
                res.push_back(node->val);
            }else{
                res[height-1] = max({res[height-1],node->val});
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
// [1,3,2,5,3,null,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

