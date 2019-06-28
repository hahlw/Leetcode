/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int left=len(root->left);
        int right=len(root->right);
        if(abs(left-right)<=1&&isBalanced(root->left)&&isBalanced(root->right))return true;
        else return false;
    }
    int len(TreeNode*t){
        if(!t)return 0;
        return max(len(t->left),len(t->right))+1;
    }
};

