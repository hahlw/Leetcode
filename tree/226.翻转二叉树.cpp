/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    /*递归*/
    TreeNode* invertTree_dg(TreeNode* root) {
        if(!root)return nullptr;
        TreeNode*left=invertTree(root->right);
        TreeNode*right=invertTree(root->left);
        root->left=left;
        root->right=right;
        return root;
    }
    /*dfs*/
    TreeNode* invertTree_dfs(TreeNode* root) {
        if(!root)return nullptr;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode*node=s.top();
            s.pop();
            TreeNode*left=node->left;
            node->left=node->right;
            node->right=left;
            if(node->left){
                s.push(node->left);
            }
            if(node->right){
                s.push(node->right);
            }
        }
        return root;
    }
    /*bfs*/
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return nullptr;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            TreeNode*left=node->left;
            node->left=node->right;
            node->right=left;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        return root;
    }
};

