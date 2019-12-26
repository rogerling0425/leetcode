/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        int mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(matrix[mid / n][mid % n] < target)
                left = mid + 1;
            else if(matrix[mid / n][mid % n] > target)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};
// @lc code=end
