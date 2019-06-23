/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int>preleft,preright,inleft,inright;
        if(preorder.size()==0)return nullptr;
        int val=preorder[0];
        TreeNode*root=new TreeNode(val);
        
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]!=val)inleft.push_back(inorder[i]);
            else break;
        }
        inright.insert(inright.begin(),inorder.begin()+inleft.size()+1,inorder.end());
        for(int i=1;i<preorder.size();i++){
            if(i<=inleft.size())preleft.push_back(preorder[i]);
            else preright.push_back(preorder[i]);
        }
        root->left=buildTree(preleft,inleft);
        root->right=buildTree(preright,inright);
        return root;
    }
};

