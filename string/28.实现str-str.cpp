/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 */
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        if (n == 0)
            return 0;
        if (n > m)
            return -1;
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[j + i] != needle[j])
                    break;
            }
            if (j == n)
                return i;
        }
        return -1;
    }
};
