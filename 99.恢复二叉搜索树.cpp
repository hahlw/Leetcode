/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode*first,*second;
    TreeNode*pre;
    void recoverTree(TreeNode* root) {
        inorder(root);
        int tmp=first->val;
        first->val=second->val;
        second->val=tmp;
    }
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        if(pre&&first==nullptr&&pre->val>=root->val){
            first=pre;
        }
        if(first!=nullptr&&pre->val>=root->val){
            second=root;
        }
        pre=root;
        inorder(root->right);
    }
};

