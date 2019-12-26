/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int i = 0, count = 1;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
                count = 1;
            }
            else if (count < 2)
            {
                nums[++i] = nums[j];
                count++;
            }
            else
            {
                count++;
            }
        }
        return i + 1;
    }
};
// @lc code=end
