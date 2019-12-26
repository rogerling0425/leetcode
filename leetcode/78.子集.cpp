/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if(nums.empty())
            return {{}};
        vector<vector<int>> ans({{}});
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = ans.size() - 1; j >= 0; j--)
            {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
// @lc code=end
