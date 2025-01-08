/*
 * @lc app=leetcode.cn id=3297 lang=rust
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
 * Total Accepted:    4K
 * Total Submissions: 8K
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
pub struct Solution;
// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn valid_substring_count(word1: String, word2: String) -> i64 {
        let mut diff: Vec<i16> = vec![0; 26];
        let n = word1.len();
        let mut ans: i64 = 0;
        for ch in word2.bytes() {
            diff[ch as usize - 'a' as usize] -= 1;
        }
        let mut cnt = diff.iter().filter(|val| **val < 0).count();
        let mut update_cnt = |ch: u8, add: i8, cnt: &mut usize| {
            let ch = ch as usize - 'a' as usize;
            diff[ch] += add as i16;
            if add == 1 && diff[ch] == 0 {
                *cnt -= 1;
            } else if add == -1 && diff[ch] == -1 {
                *cnt += 1;
            }
        };
        let mut l = 0;
        let mut r = 0;
        while r < n {
            update_cnt(word1.bytes().nth(r).unwrap(), 1, &mut cnt);
            r += 1;
            while cnt == 0 {
                ans += (n - r + 1) as i64;
                update_cnt(word1.bytes().nth(l).unwrap(), -1, &mut cnt);
                l += 1;
            }
        }
        return ans;
    }
}
// @lc code=end

/*
// @lcpr case=start
// "bcca"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abcabc"\n"aaabc"\n
// @lcpr case=end

 */
