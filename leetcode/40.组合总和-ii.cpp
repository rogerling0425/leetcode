/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        if(candidates.size() == 0)
            return {};
        sort(candidates.begin(), candidates.end());
        vector<int> oneans;
        vector<vector<int>> ans;
        backtracking(candidates, target, oneans, ans);
        return ans;
    }

    void backtracking(vector<int> candidates, int target, vector<int>& oneans, vector<vector<int>>& ans)
    {
        for(int i = 0; i < candidates.size(); i++)
        {
            if(i > 0 && candidates[i] == candidates[i - 1])
                continue;
            if(candidates[i] > target)
                return;
            oneans.push_back(candidates[i]);
            if(candidates[i] == target)
                ans.push_back(oneans);
            else
                backtracking(vector<int>(candidates.begin() + i + 1, candidates.end()), target - candidates[i], oneans, ans);
            oneans.pop_back();
        }
        return;
    }
};
// @lc code=end
