#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>>res;
        vector<int>visited(num.size(), 0);
        dfs(res,num,visited,0,{});
        return res;
    }
    void dfs(vector<vector<int>>&res,vector<int> num,vector<int>&visited,int level,vector<int>out){
        if(level==num.size()){
            res.push_back(out);
            return ;}
        for(int i=0;i<num.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                out.push_back(num[i]);
                dfs(res,num,visited,level+1,out);
                out.pop_back();
                visited[i]=0;
            }
        }
    }
};