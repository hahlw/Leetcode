/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)return res;
        TreeNode*la=root;
        queue<TreeNode*>qnode;
        qnode.push(root);
        while(!qnode.empty()){
            vector<int>cur;
            while(!qnode.empty()&&qnode.front()!=la){
                TreeNode*node=qnode.front();
                cur.push_back(node->val);
                qnode.pop();
                if(node->left)qnode.push(node->left);
                if(node->right)qnode.push(node->right);
            }
            if(qnode.front()==la){
                TreeNode*node=qnode.front();
                cur.push_back(node->val);
                res.push_back(cur);
                if(node->left)qnode.push(node->left);
                if(node->right)qnode.push(node->right);
                la=qnode.back();
                qnode.pop();
            }
        }
        return res;
    }
};

