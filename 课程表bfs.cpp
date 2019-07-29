#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int res = 0;
    int minimumSemesters(int N, vector<vector<int>>& relations)
    {
        vector<vector<int>> g(N + 1);
        vector<int> rudu(N + 1, 0);
        queue<int> q;
        //构建图
        for (int i = 0; i < relations.size(); i++) {
            g[relations[i][0]].push_back(relations[i][1]);
            rudu[relations[i][1]]++;
        }
        for (int i = 1; i <= N; i++) {
            if (rudu[i] == 0)
                q.push(i);
        }
        if (q.size() == 0)
            return -1;
        while (!q.empty()) {
            int ks = q.size();
            for (int k = 0; k < ks; k++) {
                int node = q.front();
                q.pop();
                for (int i = 0; i < g[node].size(); i++) {
                    if (--rudu[g[node][i]] == 0) {
                        q.push(g[node][i]);
                    }
                }
            }
            res++;
        }
        for (int i = 1; i <= N; i++) {
            if (rudu[i])
                return -1;
        }
        return res;
    }
};