/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string simplifyPath(string path)
    {
        vector<string> v;
        int i = 0;
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/')
                i++;
            if (i == path.size())
                break;
            int start = i;
            while (i < path.size() && path[i] != '/')
                i++;
            string s = path.substr(start, i - start);
            if (s == "..") {
                if (!v.empty())
                    v.pop_back();
            } else if (s != ".")
                v.push_back(s);
        }
        if (v.empty())
            return "/";
        string res = "";
        for (auto c : v)
            res += '/' + c;
        return res;
    }
};
