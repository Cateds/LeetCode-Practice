// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3297 lang=cpp
 * @lcpr version=30204
 *
 * [3297] 统计重新排列后包含另一个字符串的子字符串数目 I
 *
 * https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/description/
 *
 * algorithms
 * Medium (48.15%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 7.6K
 * Testcase Example:  '"bcca"\n"abc"'
 *
 * 给你两个字符串 word1 和 word2 。
 *
 * 如果一个字符串 x 重新排列后，word2 是重排字符串的 前缀 ，那么我们称字符串 x 是 合法的 。
 *
 * 请你返回 word1 中 合法 子字符串 的数目。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：word1 = "bcca", word2 = "abc"
 *
 * 输出：1
 *
 * 解释：
 *
 * 唯一合法的子字符串是 "bcca" ，可以重新排列得到 "abcc" ，"abc" 是它的前缀。
 *
 *
 * 示例 2：
 *
 *
 * 输入：word1 = "abcabc", word2 = "abc"
 *
 * 输出：10
 *
 * 解释：
 *
 * 除了长度为 1 和 2 的所有子字符串都是合法的。
 *
 *
 * 示例 3：
 *
 *
 * 输入：word1 = "abcabc", word2 = "aaabc"
 *
 * 输出：0
 *
 *
 *
 *
 * 解释：
 *
 *
 * 1 <= word1.length <= 10^5
 * 1 <= word2.length <= 10^4
 * word1 和 word2 都只包含小写英文字母。
 *
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <cstdint>
#include <string>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // // 滑动窗口 1
    // long long validSubstringCount(string &word1, string &word2) {
    //     array<int, 26> diff;
    //     int l = 0, r = 0;
    //     int n = word1.length();
    //     long long ans = 0;
    //     auto is_valid = [&](void) -> bool {
    //         for (int i = 0; i < 26; i++)
    //             if (diff[i] < 0)
    //                 return false;
    //         return true;
    //     };
    //     // Initialize the cnt_2 for word2
    //     for (auto &ch : word2)
    //         diff[ch - 'a'] -= 1;
    //     // Sliding Window
    //     while (r < n) {
    //         diff[word1[r] - 'a'] += 1;
    //         r++;
    //         while (is_valid()) {
    //             ans += n - r + 1;
    //             diff[word1[l] - 'a'] -= 1;
    //             l++;
    //         };
    //     }
    //     return ans;
    // }

    // 官解的优化滑动窗口算法。
    long long validSubstringCount(string &word1, string &word2) {
        array<int16_t, 26> diff;
        int n = word1.length();
        long long ans = 0;
        for (auto &ch : word2)
            diff[ch - 'a'] -= 1;
        int cnt = count_if(diff.begin(), diff.end(),
                           [](decltype(diff.front()) val) { return val < 0; });
        auto update_cnt = [&](char ch, int add) {
            ch -= 'a';
            diff[ch] += add;
            if (add == 1 and diff[ch] == 0)
                cnt -= 1;
            else if (add == -1 and diff[ch] == -1)
                cnt += 1;
        };
        // Sliding Window
        for (int l = 0, r = 0; r < n;) {
            update_cnt(word1[r], 1);
            r++;
            while (cnt == 0) {
                ans += n - r + 1;
                update_cnt(word1[l], -1);
                l++;
            };
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=validSubstringCount
// paramTypes= ["string","string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "ddccdddccdddccccdddccdcdcd"\n"ddc"\n
// @lcpr case=end

// @lcpr case=start
// "dcbdcdccb"\n"cdd"\n
// @lcpr case=end

// @lcpr case=start
// "bcca"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"aaabc"\n
// @lcpr case=end

// @lcpr case=start
// "ffff"\n"f"\n
// @lcpr case=end

 */
