/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if (n == 0)
            return {};
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int left = 0, right = n - 1;
        int up = 0, down = n - 1;
        int count = 1;
        int i;
        while (1)
        {
            i = left;
            while (i <= right)
                ans[up][i++] = count++;
            if (++up > down)
                break;
            i = up;
            while (i <= down)
                ans[i++][right] = count++;
            if (left > --right)
                break;
            i = right;
            while (i >= left)
                ans[down][i--] = count++;
            if (up > --down)
                break;
            i = down;
            while (i >= up)
                ans[i--][left] = count++;
            if (++left > right)
                break;
        }
        return ans;
    }
};
// @lc code=end
