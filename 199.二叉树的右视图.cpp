/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int cn=q.size();
            for(int i=0;i<cn;i++){
                TreeNode*node=q.front();
                if(i==cn-1){
                    res.push_back(node->val);
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                q.pop();
            }
        }
        return res;
    }
};

