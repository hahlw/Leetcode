/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root);
        return res;
    }
    int maxdepth(TreeNode*root){
        if(!root)
            return 0;
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};

