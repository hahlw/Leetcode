/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
         stack<TreeNode*>s;
         vector<int>res;
         TreeNode*pre=nullptr;
         while(root||!s.empty()){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(!s.empty()){
                TreeNode*node=s.top();
                if(!node->right){
                    res.push_back(node->val);
                    pre=node;
                    s.pop();
                }
                else{
                    if(pre==node->right){
                        res.push_back(node->val);
                        pre=node;
                        s.pop();
                    }
                    else{
                        //s.push(node->right);
                        root=node->right;
                    }
                }
            }
        }
        return res;
    }
};

