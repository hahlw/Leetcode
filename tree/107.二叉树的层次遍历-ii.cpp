/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ns;
        if(!root)return ns;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            vector<int>cur;
            for(int i=0;i<len;i++){
                TreeNode*node=q.front();
                cur.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                q.pop();
            }
            ns.insert(ns.begin(),cur); 
        }
        return ns;
    }
};

