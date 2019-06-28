/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root)return 0;
        int deep=0;
        q.push(root);
        while(!q.empty()){
            deep++;
            int cnt=q.size();
            for(int i =0;i<cnt;i++){
                TreeNode*node=q.front();
                if(!node->left&&!node->right)
                    return deep;
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return deep;
    }
};

