/*
 * @lc app=leetcode.cn id=1523 lang=cpp
 * @lcpr version=30112
 *
 * [1523] 在区间范围内统计奇数数目
 */

// @lcpr-template-start
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low + 1 + low % 2) / 2;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 8\n10\n
// @lcpr case=end

 */
