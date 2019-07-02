/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        int high=h(root);
        return high<0?0:
                    high-1==h(root->right)?(1<<high)+countNodes(root->right):
                    (1<<(high-1))+countNodes(root->left);
    }
    int h(TreeNode*root){
        return root==nullptr?-1:1+h(root->left);
    }
};

