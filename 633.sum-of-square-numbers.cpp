/*
 * @lc app=leetcode.cn id=633 lang=cpp
 * @lcpr version=30204
 *
 * [633] 平方数之和
 *
 * https://leetcode.cn/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (37.96%)
 * Likes:    486
 * Dislikes: 0
 * Total Accepted:    160.6K
 * Total Submissions: 417.6K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：c = 5
 * 输出：true
 * 解释：1 * 1 + 2 * 2 = 5
 *
 *
 * 示例 2：
 *
 * 输入：c = 3
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= c <= 2^31 - 1
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // bool judgeSquareSum(int c) {
    //     unordered_map<int, bool> num;
    //     for (long i = 0; i * i <= c; i++) {
    //         num[c - i * i] = true;
    //         if (num[i * i])
    //             return true;
    //     }
    //     return false;
    // }
    bool judgeSquareSum(const int &c) {
        int a=0, b=ceil(sqrt(c));
        while (a<=b) {
            auto temp = (long)a*a+(long)b*b;
            if (temp==c)
                return true;
            else if (temp>c)
                b--;
            else 
                a++;
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
