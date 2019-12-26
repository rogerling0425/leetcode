/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if(nums.size() == 0)    return 0;
        int ans = nums[0], cursum = max(nums[0], 0);
        for(int i = 1; i < nums.size(); i++)
        {
            ans = max(ans, cursum + nums[i]);
            cursum = max(cursum + nums[i], 0);
        }
        return ans;
    }
};
// @lc code=end
