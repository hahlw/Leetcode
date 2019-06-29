/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        while(!root)return ;
        TreeNode*node=root;
        while(node){
            while(node&&!node->left){
                node=node->right;
            }
            if(!node)return ;
            TreeNode*cur=node->left;
            while(cur->right){
                cur=cur->right;
            }
            cur->right=node->right;
            node->right=node->left;
            node->left=nullptr;
        }
    }
};

