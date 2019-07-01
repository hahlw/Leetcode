/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>res;
        while(!s.empty()||root){
            while(root){
                s.push(root);
                res.push_back(root->val);
                root=root->left;
            }
            if(!s.empty()){
                TreeNode*node=s.top();
                root=node->right;
                s.pop();
            }
        }
        return res;
    }
};

