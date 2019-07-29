/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        helper(nums, res, cur, 0);
        return res;
    }

    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur,
        int start)
    {
        if (start >= nums.size()) {
            res.push_back(cur);
            return;
        }
        res.push_back(cur);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            cur.push_back(nums[i]);
            helper(nums, res, cur, i + 1);
            cur.pop_back();
        }
    }
};
