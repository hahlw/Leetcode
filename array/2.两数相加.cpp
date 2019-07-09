/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *pl1 = l1;
    ListNode *pl2 = l2;

    // ListNode head(0);
    // ListNode *p = &head;


    ListNode head(0);
    ListNode *p = &head;
    while (pl1&&pl2)
    {
        int val1 = pl1->val;
        int val2 = pl2->val;

        int val3 = (val1 + val2 + tmp) % 10;
        tmp = (val1 + val2 + tmp) / 10;

        p->next = (ListNode *)malloc(sizeof( ListNode));
        p=p->next;
        p->val = val3;
        p->next = NULL;
        
        pl1 = pl1->next;
        pl2 = pl2->next;
    }

    if (pl1 == NULL)
    {
        pl1 = pl2;
        pl2 = NULL;

        while (pl1)
        {
            int val3 = (pl1->val + tmp)%10;
            tmp = (pl1->val + tmp) / 10;
            p->next = (ListNode *)malloc(sizeof(ListNode));
            p=p->next;
            p->val = val3;
            p->next = NULL;
        }
    }

    if (tmp != 0)
    {
        p->next = (ListNode *)malloc(sizeof(ListNode));
        p=p->next;
        p->val = tmp;
        p->next = NULL;
    }

    return head.next;
    }
};

