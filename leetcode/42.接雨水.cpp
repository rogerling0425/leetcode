/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            int lrmin = min(height[left], height[right]);
            if (height[left] <= height[right])
            {
                left++;
                while (left < right && height[left] < lrmin)
                    ans += lrmin - height[left++];
            }
            else
            {
                right--;
                while(left < right && height[right] < lrmin)
                    ans += lrmin - height[right--];
            }
        }
        return ans;
    }
};
// @lc code=end
