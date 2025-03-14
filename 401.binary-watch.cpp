/*
 * @lc app=leetcode.cn id=401 lang=cpp
 * @lcpr version=30204
 *
 * [401] 二进制手表
 *
 * https://leetcode.cn/problems/binary-watch/description/
 *
 * algorithms
 * Easy (63.19%)
 * Likes:    443
 * Dislikes: 0
 * Total Accepted:    81.8K
 * Total Submissions: 129.5K
 * Testcase Example:  '1'
 *
 * 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。每个 LED 代表一个 0 或
 * 1，最低位在右侧。
 *
 *
 * 例如，下面的二进制手表读取 "4:51" 。
 *
 *
 *
 *
 * 给你一个整数 turnedOn ，表示当前亮着的 LED 的数量，返回二进制手表可以表示的所有可能时间。你可以 按任意顺序 返回答案。
 *
 * 小时不会以零开头：
 *
 *
 * 例如，"01:00" 是无效的时间，正确的写法应该是 "1:00" 。
 *
 *
 * 分钟必须由两位数组成，可能会以零开头：
 *
 *
 * 例如，"10:2" 是无效的时间，正确的写法应该是 "10:02" 。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：turnedOn = 1
 * 输出：["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
 *
 *
 * 示例 2：
 *
 * 输入：turnedOn = 9
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= turnedOn <= 10
 *
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<vector<int>> nums = {
            {0},
            {1, 2, 4, 8, 16, 32},
            {3, 5, 6, 9, 10, 12, 17, 18, 20, 24, 33, 34, 36, 40, 48},
            {7, 11, 13, 14, 19, 21, 22, 25, 26, 28, 35, 37, 38, 41, 42, 44, 49, 50, 52, 56},
            {15, 23, 27, 29, 30, 39, 43, 45, 46, 51, 53, 54, 57, 58},
            {31, 47, 55, 59}};
        vector<string> Res;
        if (turnedOn > 8)
            return Res;
        for (int i = 0; i <= min(3, turnedOn); i++) {
            if (turnedOn - i > 5)
                continue;
            for (auto &hour : nums[i]) {
                if (hour >= 12)
                    break;
                for (auto &minute : nums[turnedOn - i])
                    Res.push_back(to_string(hour) + ':' + (minute < 10 ? "0" : "") + to_string(minute));
                    // Res.push_back(format("{}:{:02d}", hour, minute));
            }
        }
        return Res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 9\n
// @lcpr case=end

 */
