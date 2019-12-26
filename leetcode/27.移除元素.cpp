/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = -1;
        for(int j = 0; j < nums.size(); j++)
        {
            if(val != nums[j])
            {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};
// @lc code=end
