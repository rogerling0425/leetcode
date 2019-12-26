/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int curtarget = target - nums[i];
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = nums.size() - 1;
                while(left < right)
                {
                    int sum = nums[j] + nums[left] + nums[right];
                    if(sum < curtarget)
                        left++;
                    else if(sum > curtarget)
                        right--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left + 1 < right && nums[left] == nums[left + 1])
                            left++;
                        while(left < right - 1 && nums[right] == nums[right - 1])
                            right--;
                        left++, right--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
