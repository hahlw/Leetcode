/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return is(root->left,root->right);
    }
    bool is(TreeNode*p,TreeNode*q){
        if(!p&&!q)return true;
        if(!p&&q)return false;
        if(!q&&p)return false;
        return (p->val==q->val)&&is(p->left,q->right)&&is(p->right,q->left);
    }
};

