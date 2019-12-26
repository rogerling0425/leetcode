/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                break;
        }
        if(left > right)   
            return {-1, -1};
        int i = mid, j = mid;
        while(i >= 0 && nums[i] == nums[mid])
            i--;
        while(j < nums.size() && nums[j] == nums[mid])
            j++;
        return {i + 1, j - 1};
    }
};
// @lc code=end
