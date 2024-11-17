/*
 * @lc app=leetcode.cn id=191 lang=cpp
 * @lcpr version=30204
 *
 * [191] 位1的个数
 *
 * https://leetcode.cn/problems/number-of-1-bits/description/
 *
 * algorithms
 * Easy (78.11%)
 * Likes:    658
 * Dislikes: 0
 * Total Accepted:    404.9K
 * Total Submissions: 517.9K
 * Testcase Example:  '11'
 *
 * 给定一个正整数 n，编写一个函数，获取一个正整数的二进制形式并返回其二进制表达式中 设置位 的个数（也被称为汉明重量）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 11
 * 输出：3
 * 解释：输入的二进制串 1011 中，共有 3 个设置位。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 128
 * 输出：1
 * 解释：输入的二进制串 10000000 中，共有 1 个设置位。
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 2147483645
 * 输出：30
 * 解释：输入的二进制串 1111111111111111111111111111101 中，共有 30 个设置位。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果多次调用这个函数，你将如何优化你的算法？
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};
// @lc code=end


/*
// @lcpr case=start
// 11\n
// @lcpr case=end

// @lcpr case=start
// 128\n
// @lcpr case=end

// @lcpr case=start
// 2147483645\n
// @lcpr case=end

 */

