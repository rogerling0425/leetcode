/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right)
        {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if (height[left] <= height[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};
// @lc code=end
