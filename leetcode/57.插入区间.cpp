/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        if(intervals.empty())   return {};
        auto compare = [](vector<int> i, vector<int> j) -> bool { return i[0] < j[0]; };
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans({intervals[0]});
        for (int i = 1; i < intervals.size(); i++)
        {
            if (ans.back()[1] < intervals[i][0])
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        return ans;
    }
};
// @lc code=end

