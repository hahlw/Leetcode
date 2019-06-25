/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return nullptr;
        int lo=0,hi=nums.size()-1;
        int mid=lo+(hi+lo)/2;
        vector<int>left,right;
        for(int i =0;i<nums.size();i++){
            if(i<mid)left.push_back(nums[i]);
            if(i>mid)right.push_back(nums[i]);
        }
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);
        return root;
    }
};

