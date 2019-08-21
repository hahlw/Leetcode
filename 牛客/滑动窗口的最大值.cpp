#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

class Solution {
public:
    //const 不能修改数据。这种方法GG;
    // vector<int> maxInWindows( vector<int>& num, unsigned int size)
    // {
    //     int n = num.size();
    //     if(size==0||num.empty()||size>n)
    //         return {};
    //     for (int k = 1; k < size;k++){
    //         for (int i = 0; i < n-k; i++) {
    //             num[i]= max(num[i], num[i + 1]);
    //         }
    //     }
    //     vector<int> res(num.begin(), num.end() - size + 1);
    //     return res;
    // }
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> deq;//存下标
        for (int  i = 0; i < num.size();i++){

            while(!deq.empty()&&num[deq.back()]<=num[i])
                deq.pop_back();

            while(!deq.empty()&&(i-deq.front()+1)>size)
                deq.pop_front();

            deq.push_back(i);
            if(size&&i+1>=size)
                res.push_back(num[deq.front()]);
        }
        return res;
    }
};