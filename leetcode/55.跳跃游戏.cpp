/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int cur = 0, pre = 0, i = 0;
        while (cur < nums.size() - 1)
        {
            for (; i <= pre; i++)
                cur = max(cur, i + nums[i]);
            if (pre == cur)
                return false;
            pre = cur;
        }
        return true;
    }
};
// @lc code=end
