/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        int cur=0;
        stack<TreeNode*>s;
        while(!s.empty()||root){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(!s.empty()){
                cur++;
                TreeNode*node=s.top();
                s.pop();
                if(k==cur)return node->val;
                root=node->right;
            }
        }
        return 0;
    }
};

