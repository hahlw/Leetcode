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
        vector<int> visit(N + 1, 0);
        unordered_set<int> s;
        vector<int> rudu(N + 1, 0);
        int depth = 1;
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
        //从每一个入度为零的顶点出发，dfs。
        for (int i = 0; i < q.size(); i++) {
            int k = q.front();
            q.pop();
            visit[k] = 1;
            if (dfs(g, visit, k, depth))
                return -1;
            visit[k] = 0;
        }
        return res;
    }
    //true 有环
    bool dfs(vector<vector<int>>& g, vector<int>& visit, int start, int& depth)
    {
        for (int i = 0; i < g[start].size(); i++) {
            if (visit[g[start][i]] == 0) {
                visit[g[start][i]] = 1;
                res = max(res, ++depth);
                if (dfs(g, visit, g[start][i], depth))
                    return true;
                depth--;
                visit[g[start][i]] = 0;
            } else {
                return true;
            }
        }
        return false;
    }
};