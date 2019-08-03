#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> viterbi(vector<vector<double>> A, vector<vector<double>> B, vector<double> pi, vector<int> target)
{
    /*
		target=[0,1,0]
	*/
    int t = target.size(); //序列的长度
    int nNum = A.size(); //隐状态的个数。
    vector<int> res;
    vector<vector<double>> dp(t, vector<double>(nNum, 0.0));
    vector<vector<int>> w(nNum, vector<int>(nNum, -1));

    for (int i = 0; i < nNum; i++)
        dp[0][i] = pi[i] * B[i][target[0]];
    for (int i = 1; i < t; i++) { //t时刻
        for (int j = 0; j < nNum; j++) { //t时刻所有可能的状态。
            double max_pi = 0.0;
            for (int k = 0; k < nNum; k++) { //计算t时刻J状态最有可能是由t-1时刻哪一个状态转移过来的。
                if (dp[i - 1][k] * A[k][j] > max_pi) {
                    max_pi = dp[i - 1][k] * A[k][j];
                    w[i][j] = k;
                }
            }
            dp[i][j] = max_pi * B[j][target[i]];
        }
    }
    int lable = -1;
    double max_pp = 0.0;
    for (int i = 0; i < nNum; i++) {
        if (dp[t - 1][i] > max_pp) {
            lable = i;
            max_pp = dp[t - 1][i];
        }
    }
    res.insert(res.begin(), lable);

    for (int j = t - 1; j > 0; j--) {
        int pre = res.front();
        res.insert(res.begin(), w[j][pre]);
    }
    return res;
}

int main()
{
    vector<vector<double>> A = { { 0.5, 0.2, 0.3 }, { 0.3, 0.5, 0.2 }, { 0.2, 0.3, 0.5 } };
    vector<vector<double>> B = { { 0.5, 0.5 }, { 0.4, 0.6 }, { 0.7, 0.3 } };
    vector<double> pi = { 0.2, 0.4, 0.4 };
    vector<int> target = { 0, 1, 0 };
    vector<int> res = viterbi(A, B, pi, target);
    for (auto a : res)
        cout << a << endl;
    system("pause");
    return 0;
}