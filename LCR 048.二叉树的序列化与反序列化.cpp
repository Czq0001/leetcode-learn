#include<iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 048 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 048] 二叉树的序列化与反序列化
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

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) {
            return "#";
        }
        queue<TreeNode*>q;
        vector<string> out;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if(node == nullptr){
                out.push_back("#");
            }else{
                out.push_back(to_string(node->val));
            }
            if(node){
                q.push(node->left);
            }
            if(node){
                q.push(node->right);
            }
        }
        string res = "";
        for(int i = 0;i < out.size();i++){
            res += out[i];
            if(i != out.size()-1){
                res += ",";
            }
        }
        return res;
    }

    vector<string> split(string data,char m){
        vector<string> res;
        string cur = "";
        for(char c : data){
            if(c == m){
                res.push_back(cur);
                cur.clear();
            }else{
                cur.push_back(c);
            }
        }
        res.push_back(cur);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#" || data.empty()) return nullptr;
        vector<string> tok = split(data, ',');
        if(tok.empty() || tok[0] == "#"){
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(tok[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < (int)tok.size()) {
            TreeNode *cur = q.front();
            q.pop();
            if(i < (int)tok.size() && tok[i] != "#"){
                cur->left = new TreeNode(stoi(tok[i]));
                q.push(cur->left);
            }
            i++;
            if(i < (int)tok.size() && tok[i] != "#"){
                cur->right = new TreeNode(stoi(tok[i]));
                q.push(cur->right);
            }
            i++;
        }
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,null,4,5]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

