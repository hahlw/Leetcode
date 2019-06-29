/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode*lo=head,*fa=head;
        while(fa->next&&fa->next->next){
            fa=fa->next->next;
            lo=lo->next;
        }
        fa=lo->next;
        lo->next=nullptr;
        lo=head;
        ListNode*left=sortList(lo);
        ListNode*right=sortList(fa);
        return merge(left,right);
    }
    ListNode*merge(ListNode*l1,ListNode*l2){
        ListNode*cur=new ListNode(-1);
        ListNode*n=cur;
        while(l1&&l2){
            if(l1->val<=l2->val){
                ListNode*node=l1->next;
                l1->next=nullptr;
                n->next=l1;
                n=n->next;
                l1=node;
            }
            else{
                ListNode*node=l2->next;
                l2->next=nullptr;
                n->next=l2;
                n=n->next;
                l2=node;
            }
        }
        if(l1)n->next=l1;
        if(l2)n->next=l2;
        return cur->next;
    }
};

