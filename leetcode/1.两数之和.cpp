/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        if (nums.size() < 2)
            return {};
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.count(target - nums[i]))
            {
                return {hash[target - nums[i]], i};
            }
            else
            {
                hash[nums[i]] = i;
            }
        }
        return {};
    }
};
// @lc code=end
