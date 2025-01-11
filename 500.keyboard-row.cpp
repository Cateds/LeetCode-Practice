// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=500 lang=cpp
 * @lcpr version=30204
 *
 * [500] 键盘行
 *
 * https://leetcode.cn/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (74.02%)
 * Likes:    266
 * Dislikes: 0
 * Total Accepted:    81.9K
 * Total Submissions: 110.7K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
 *
 * 请注意，字符串 不区分大小写，相同字母的大小写形式都被视为在同一行。
 *
 * 美式键盘 中：
 *
 *
 * 第一行由字符 "qwertyuiop" 组成。
 * 第二行由字符 "asdfghjkl" 组成。
 * 第三行由字符 "zxcvbnm" 组成。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：words = ["Hello","Alaska","Dad","Peace"]
 *
 * 输出：["Alaska","Dad"]
 *
 * 解释：
 *
 * 由于不区分大小写，"a" 和 "A" 都在美式键盘的第二行。
 *
 *
 * 示例 2：
 *
 *
 * 输入：words = ["omk"]
 *
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：words = ["adsdf","sfd"]
 *
 * 输出：["adsdf","sfd"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 20
 * 1 <= words[i].length <= 100
 * words[i] 由英文字母（小写和大写字母）组成
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
    vector<string> findWords(vector<string> &words) {
        array<uint8_t, 26> lines = {
            2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
        vector<string> ans;
        for (auto &wr : words) {
            uint8_t prvLine = 0;
            bool inSameLine = true;
            for (auto &ch : wr) {
                if (prvLine) {
                    if (prvLine != lines[(ch | 32) - 'a']) {
                        inSameLine = false;
                        break;
                    }
                } else
                    prvLine = lines[(ch | 32) - 'a'];
            }
            if (inSameLine)
                ans.push_back(wr);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["Hello","Alaska","Dad","Peace"]\n
// @lcpr case=end

// @lcpr case=start
// ["omk"]\n
// @lcpr case=end

// @lcpr case=start
// ["adsdf","sfd"]\n
// @lcpr case=end

 */
