#include<iostream>
using namespace std;
/*
@lc app=leetcode.cn id=LCR 043 lang=cpp
@lcpr version=30307
 *
[LCR 043] 完全二叉树插入器
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
 

class CBTInserter {
public:
    queue<TreeNode*> history;
    TreeNode *root_;
    CBTInserter(TreeNode* root) {
        root_ = root;
        //层序遍历
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p->left == nullptr || p->right == nullptr){
                history.push(p);
            }
            if(p->left){
                q.push(p->left);
            }
            if(p->right){
                q.push(p->right);
            }
        }
    }
    
    int insert(int v) {
        if(history.front()->left == nullptr){
            TreeNode *cur = new TreeNode(v);
            history.front()->left = cur;
            history.push(cur);
            return history.front()->val;
        }
        if(history.front()->right == nullptr){
            TreeNode *cur = new TreeNode(v);
            history.front()->right = cur;
            int ans = history.front()->val;
            history.pop();
            history.push(cur);
            return ans;
        }
        return 0;
    }
    TreeNode* get_root() {
        return root_;
    }
};

/**
Your CBTInserter object will be instantiated and called as such:
CBTInserter* obj = new CBTInserter(root);
int param_1 = obj->insert(v);
TreeNode* param_2 = obj->get_root();
 */
// @lc code=end



/*
// @lcpr case=start
// ["CBTInserter","insert","get_root"]\n[[[1]],[2],[]]\n["CBTInserter","insert","insert","get_root"]\n[[[1,2,3,4,5,6]],[7],[8],[]]\n
// @lcpr case=end

 */

