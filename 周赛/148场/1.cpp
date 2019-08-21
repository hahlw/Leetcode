#include<iostream>
#include<vector>
using namespace std;


/*
输入：nums = [1,2,3]
输出：2
解释：我们可以把 2 递减到 0，或把 3 递减到 1。
 */

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n=nums.size();
        vector<int> tmp = nums;
        vector<int> dp1(n, 0),dp2(n,0);
        for (int i = 1; i < n;i++){
            if(i%2==1){
                if(tmp[i]>tmp[i-1])
                    dp1[i] = dp1[i-1];
                else{
                    dp1[i] = dp1[i - 1] + tmp[i - 1] - tmp[i] + 1;
                    tmp[i] = tmp[i - 1] + 1;
                }
            }
            else{
                if(tmp[i]<tmp[i-1])
                    dp1[i] = dp1[i - 1];
                else{
                    dp1[i] = dp1[i - 1] + tmp[i] - tmp[i - 1] + 1;
                    tmp[i] = tmp[i - 1] - 1;
                }
            }
        }
        tmp = nums;
        for (int i = 1; i < n;i++){
            if(i%2==1){
                if(tmp[i]>tmp[i-1]){
                    dp2[i] = dp2[i - 1] + tmp[i] - tmp[i - 1] + 1;
                    tmp[i] = tmp[i - 1] - 1;
                }
                else{
                    dp2[i] = dp2[i - 1];
                }
            }
            else{
                if(tmp[i]>tmp[i-1]){
                    dp2[i]=dp2[i-1];
                }
                else{
                    dp2[i] = dp2[i - 1] + tmp[i - 1] - tmp[i] + 1;
                    tmp[i] = tmp[i - 1] + 1;
                }
            }
        }
        return min(dp1[n - 1], dp2[n - 1]);
    }
};