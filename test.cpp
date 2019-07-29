#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] <= b[2];
}
class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& conections)
    {
        unordered_set<int> s;
        sort(conections.begin(), conections.end(), cmp);
        int bian = 0;
        int res = 0;
        for (auto vec : conections) {
            if (s.find(vec[0]) != s.end() && s.find(vec[1]) != s.end())
                continue;
            else {
                res += vec[2];
                if (s.find(vec[0]) == s.end())
                    s.insert(vec[0]);
                if (s.find(vec[1]) == s.end())
                    s.insert(vec[1]);
                bian++;
            }
        }
        if ((bian + 1) != s.size())
            return -1;
        return res;
    }
};

int main()
{
    vector<vector<int>> conections = { { 1, 2, 5 }, { 1, 3, 6 }, { 2, 3, 1 } };
    Solution s = Solution();
    int a = s.minimumCost(3, conections);
    cout << a;
    return 0;
}