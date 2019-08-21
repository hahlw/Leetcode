/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxFre = 0;
        for(auto nu:nums){
            mp[nu]++;
            maxFre = max(maxFre, mp[nu]);
        }
        vector<vector<int>> buckets(maxFre+1);
        for(auto m:mp){
            buckets[m.second].push_back(m.first);
        }
        vector<int> res;
        for (int i = maxFre; i >= 0 && k > 0;i--){
            if(!buckets[i].empty()){
                for(auto bu:buckets[i]){
                    if(k>0){
                        res.push_back(bu);
                        k--;
                    }
                    else
                        break;
                }
            }
        }
        return res;
    }
};

