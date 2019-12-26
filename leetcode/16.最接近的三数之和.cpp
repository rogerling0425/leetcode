/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() < 3)
            return INT_MIN;
        int gap = INT_MAX, ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target)
                {
                    if(target - sum < gap)
                    {
                        gap = target - sum;
                        ans = sum;
                    }
                    left++;
                }
                else if (sum > target)
                {
                    if(sum - target < gap)
                    {
                        gap = sum - target;
                        ans = sum;
                    }
                    right--;                
                }
                else
                    return target ;
            }
        }
        return ans;
    }
};
// @lc code=end
