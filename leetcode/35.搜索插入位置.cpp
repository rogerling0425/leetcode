/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return 0;
        int left = 0, right = nums.size();
        int mid;
        while (left < right - 1)
        {
            mid = left + (right - left) / 2;
            if(target > nums[mid])
                left = mid;
            else if (target < nums[mid])
                right = mid;
            else
                return mid;
        }
        while(left < nums.size() && nums[left] < target)
            left++;
        return left;
    }
};
// @lc code=end
