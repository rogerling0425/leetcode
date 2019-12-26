/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int pre = 0, cur = 0, i = 0;
        int ans = 0;
        while(cur < nums.size() - 1)
        {
            for(; i <= pre; i++)
            {
                cur = max(cur, i + nums[i]);
            }
            ans++;
            pre = cur;
        }
        return ans;
    }
};
// @lc code=end
