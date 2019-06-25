/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        vector<int>inleft,inright,pleft,pright;
        if(inorder.size()==0)return nullptr;
        if(inorder.size()!=postorder.size()){
            cout<<"11111";
            return nullptr;
        }
        int val=postorder[postorder.size()-1];
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]!=val)inleft.push_back(inorder[i]);
            else break;
        }
        inright.insert(inright.begin(),inorder.begin()+inleft.size()+1,inorder.end());
        for(int j=0;j<postorder.size()-1;j++){
            if(j<inleft.size())pleft.push_back(postorder[j]);
            else pright.push_back(postorder[j]);
        }
        TreeNode*root=new TreeNode(val);
        root->left=buildTree(inleft,pleft);
        root->right=buildTree(inright,pright);
        return root;
    }
};

