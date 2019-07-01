/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        vector<int>res;
        findsum(root,res,0);
        int sum=0;
        for(int i=0;i<res.size();i++){
            sum+=res[i];
        }
        return sum;
    }
    void findsum(TreeNode*root,vector<int>&res,int cur){
        cur=cur*10+root->val;
        if(!root->left&&!root->right){
            res.push_back(cur);
            return ;
        }
        if(root->left){
            findsum(root->left,res,cur);
        }
        if(root->right){
            findsum(root->right,res,cur);
        }
        cur/=10;    
    }
};

