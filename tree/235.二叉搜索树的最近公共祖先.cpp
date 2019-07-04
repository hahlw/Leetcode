/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    /*递归 */
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val<min(p->val,q->val))
            return lowestCommonAncestor(root->right,p,q);
        if(root->val>max(p->val,q->val))
            return lowestCommonAncestor(root->left,p,q);
        else return root;
    }
    /*非递归 */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==q||root==p)return root;
        while(root){
            if(root->val<min(p->val,q->val))
                root=root->right;
            else if(root->val>max(p->val,q->val))
                root=root->left;
            else break;
        }
        return root;
    }
};

