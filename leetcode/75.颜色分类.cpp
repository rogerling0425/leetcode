/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        for(int i = 0; i <= right; i++)
        {
            if(nums[i] == 0)
                swap(nums[i], nums[left++]);
            else if(nums[i] == 2)
                swap(nums[i--], nums[right--]);
        }
    }
};
// @lc code=end
