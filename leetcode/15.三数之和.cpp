/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left + 1 < right && nums[left] == nums[left + 1])
                        left++;
                    while(left < right - 1 && nums[right] == nums[right-1])
                        right--;
                    left++,right--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
