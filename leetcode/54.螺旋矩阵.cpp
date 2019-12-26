/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int up = 0, down = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> ans;
        int i;
        while (1)
        {
            i = left;
            while (i <= right)
                ans.push_back(matrix[up][i++]);
            if (++up > down)
                break;
            i = up;
            while (i <= down)
                ans.push_back(matrix[i++][right]);
            if (left > --right)
                break;
            i = right;
            while (i >= left)
                ans.push_back(matrix[down][i--]);
            if (up > --down)
                break;
            i = down;
            while (i >= up)
                ans.push_back(matrix[i--][left]);
            if (++left > right)
                break;
        }
        return ans;
    }
};
// @lc code=end
