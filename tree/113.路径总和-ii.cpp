/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>cur;
        if(!root)return res;
        findsum(root,res,cur,sum); 
        return res;             
    }
    void findsum(TreeNode*root,vector<vector<int>>&res,vector<int>&cur,int sum){
        if(!root)
            return;
        cur.push_back(root->val);
        if(root->val==sum&&!root->left&&!root->right){
           res.push_back(cur); 
           return;
        }
        findsum(root->left,res,cur,sum-root->val);
        findsum(root->right,res,cur,sum-root->val);
        cur.pop_back();
    }
};

