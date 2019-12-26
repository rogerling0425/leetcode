/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty())
            return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[0] == board[i][j])
                {
                    visited[i][j] = true;
                    if (dfs(board, word, 0, visited, i, j))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string word, int i, vector<vector<bool>> &visited, int x, int y)
    {
        if (word.size() - 1 == i)
            return true;
        if (x - 1 >= 0 && word[i + 1] == board[x - 1][y] && !visited[x - 1][y])
        {
            visited[x - 1][y] = true;
            if(dfs(board, word, i + 1, visited, x - 1, y))
                return true;
            visited[x - 1][y] = false;
        }
        if (x + 1 < board.size() && word[i + 1] == board[x + 1][y] && !visited[x + 1][y])
        {
            visited[x + 1][y] = true;
            if(dfs(board, word, i + 1, visited, x + 1, y))
                return true;
            visited[x + 1][y] = false;
        }
        if (y - 1 >= 0 && word[i + 1] == board[x][y - 1] && !visited[x][y - 1])
        {
            visited[x][y - 1] = true;
            if(dfs(board, word, i + 1, visited, x, y - 1))
                return true;
            visited[x][y - 1] = false;
        }
        if (y + 1 < board[0].size() && word[i + 1] == board[x][y + 1] && !visited[x][y + 1])
        {
            visited[x][y + 1] = true;
            if(dfs(board, word, i + 1, visited, x, y + 1))
                return true;
            visited[x][y + 1] = false;
        }
        return false;
    }
};
// @lc code=end
