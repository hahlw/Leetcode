/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2)
    {
        int n1 = num1.size(), n2 = num2.size();
        int k = n1 + n2 - 1;
        vector<int> res(n1 + n2, 0);
        if (num1[0] == '0' || num2[0] == '0')
            return "0";

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (auto c : res) {
            cout << c << endl;
        }
        int carry = 0;
        for (int i = k; i >= 0; i--) {
            res[i] = res[i] + carry;
            carry = res[i] / 10;
            res[i] = res[i] % 10;
        }
        string str = "";
        int j = 0;
        while (j <= k) {
            if (res[j] != 0)
                break;
            j++;
        }
        for (; j <= k; j++) {
            str += (res[j] + '0');
        }
        return str;
    }
};
