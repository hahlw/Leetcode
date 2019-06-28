/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    /*
    关键是只有从根节点到叶子结点的所有路径的和才可以加起来，
    那么我们返回true的条件不但是要sum==0而且要是根节点。
    */
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;
        if(sum==root->val&&!root->left&&!root->right)return true;
        else
        {
            //如果左右结点有一个不为空,那么这个结点直接返回false.
            return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
        }
        return false;
        
    }
    
};

