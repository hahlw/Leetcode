#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int pf(vector<vector<int>> work, int friends)
{
    int res = -1;
    for (int i = 0; i < work.size(); i++) {
        if (friends >= work[i][0])
            res = max(res, work[i][1]);
    }
    return res;
}
bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[1] > b[1];
}
int main()
{
    int work_num = 0, friend_num = 0;
    cin >> work_num >> friend_num;
    vector<vector<int>> work(work_num, vector<int>(2, 0));
    int i = 0;
    while (work_num--) {
        int a = 0, b = 0;
        cin >> a >> b;
        work[i][0] = a;
        work[i][1] = b;
        cout << a << b << endl;
    }
    //sort(work.begin(), work.end(), cmp);
    while (friend_num--) {
        int c = 0;
        cin >> c;
        int res = pf(work, c);
        cout << res;
    }
    return 0;
}