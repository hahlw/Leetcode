class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        int n = pushV.size();
        stack<int> stack1;
        int k = 0;
        for (int i = 0; i < n; i++) {
            int tmp = popV[i];
            if (k < n && stack1.empty())
                stack1.push(pushV[k++]);
            while (k < n && stack1.top() != tmp)
                stack1.push(pushV[k++]);
            if (stack1.top() == tmp) {
                stack1.pop();
            } else {
                return false;
            }
        }
        return true;
    }
};