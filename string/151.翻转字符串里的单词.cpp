/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s)
    {
        if (s.empty())
            return "";
        int lo = 0, hi = s.size() - 1;
        while (lo <= hi && s[lo] == ' ')
            lo++;
        while (lo <= hi && s[hi] == ' ')
            hi--;
        if (lo > hi)
            return "";
        int left = lo, flag = 0;
        for (int i = lo; i <= hi; i++) {
            if (s[i] != ' ' || (s[i] == ' ' && flag == 0)) {
                s[left++] = s[i];
                if (s[i] == ' ')
                    flag++;
                if (s[i] != ' ')
                    flag = 0;
            }
        }
        s = s.substr(lo, left - lo);
        reverse(s.begin(), s.end());
        lo = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + lo, s.begin() + i);
                lo = i + 1;
            }
        }
        reverse(s.begin() + lo, s.end());

        return s;
    }
};
