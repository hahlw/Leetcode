/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(!root)return root;
        Node*cur=root;
        q.push(root);
        while(!q.empty()){
            Node*pre=nullptr;
            Node*second=nullptr;
            int qs=q.size();
            for(int i=0;i<qs;i++){
                if(i==0){
                    pre=q.front();
                }
                else{
                    pre->next=q.front();
                    pre=pre->next;
                }
                Node*node=q.front();
                //cout<<node->val<<endl;
                if(node->left){
                    q.push(node->left);
                    q.push(node->right);
                }
                q.pop();

            }
        }
        return root;
    }
};

