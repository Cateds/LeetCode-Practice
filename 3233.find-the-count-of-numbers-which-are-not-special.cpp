/*
 * @lc app=leetcode.cn id=3233 lang=cpp
 * @lcpr version=30204
 *
 * [3233] 统计不是特殊数字的数字数量
 *
 * https://leetcode.cn/problems/find-the-count-of-numbers-which-are-not-special/description/
 *
 * algorithms
 * Medium (30.08%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 18.8K
 * Testcase Example:  '5\n7'
 *
 * 给你两个 正整数 l 和 r。对于任何数字 x，x 的所有正因数（除了 x 本身）被称为 x 的 真因数。
 *
 * 如果一个数字恰好仅有两个 真因数，则称该数字为 特殊数字。例如：
 *
 *
 * 数字 4 是 特殊数字，因为它的真因数为 1 和 2。
 * 数字 6 不是 特殊数字，因为它的真因数为 1、2 和 3。
 *
 *
 * 返回区间 [l, r] 内 不是 特殊数字 的数字数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： l = 5, r = 7
 *
 * 输出： 3
 *
 * 解释：
 *
 * 区间 [5, 7] 内不存在特殊数字。
 *
 *
 * 示例 2：
 *
 *
 * 输入： l = 4, r = 16
 *
 * 输出： 11
 *
 * 解释：
 *
 * 区间 [4, 16] 内的特殊数字为 4 和 9。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= l <= r <= 10^9
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int nonSpecialCount(const int &l, const int &r) {
        int ans = r - l + 1;
        auto isPrime =
            [](const int &val) -> bool {
            if (val == 1)
                return false;
            else if (val == 2)
                return true;
            for (int i = 2; i * i <= val; i++)
                if (!(val % i))
                    return false;
            return true;
        };
        for (int i = ceil(sqrt(l)); i * i <= r; i++)
            if (isPrime(i))
                ans--;
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n7\n
// @lcpr case=end

// @lcpr case=start
// 4\n16\n
// @lcpr case=end

 */
