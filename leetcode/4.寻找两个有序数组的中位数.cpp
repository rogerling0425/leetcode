/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if ((nums1.size() + nums2.size()) % 2 == 0)
            return (double)(findKth(nums1, nums2, (nums1.size() + nums2.size()) / 2) + findKth(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1)) / 2;
        else
            return (double)findKth(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
    }

    int findKth(vector<int> nums1, vector<int> nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findKth(nums2, nums1, k);
        if (m == 0)
            return nums2[k - 1];
        if (k == 1)
            return min(nums1[0], nums2[0]);
        int i = min(m, k / 2), j = min(n, k / 2);
        if (nums1[i - 1] > nums2[j - 1])
            return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
        else
            return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
    }
};
// @lc code=end
