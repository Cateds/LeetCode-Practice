/*
 * @lc app=leetcode.cn id=3138 lang=cpp
 * @lcpr version=30204
 *
 * [3138] 同位字符串连接的最小长度
 *
 * https://leetcode.cn/problems/minimum-length-of-anagram-concatenation/description/
 *
 * algorithms
 * Medium (36.08%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 12.8K
 * Testcase Example:  '"abba"'
 *
 * 给你一个字符串 s ，它由某个字符串 t 和若干 t  的 同位字符串 连接而成。
 * 
 * 请你返回字符串 t 的 最小 可能长度。
 * 
 * 同位字符串 指的是重新排列一个单词得到的另外一个字符串，原来字符串中的每个字符在新字符串中都恰好只使用一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abba"
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 一个可能的字符串 t 为 "ba" 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cdef"
 * 
 * 输出：4
 * 
 * 解释：
 * 
 * 一个可能的字符串 t 为 "cdef" ，注意 t 可能等于 s 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含小写英文字母。
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
#include <cstdint>
#include <utility>
#include <vector>
#include <map>
#include <valarray>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minAnagramLength(string &s) {
        int n = s.length();
        auto isValid = [&](int sublen) -> bool {
            vector<int> cnt0(26), cnt1;
            int ptr;
            for (ptr = 0; ptr<sublen; ptr++) {
                cnt0[s[ptr]-'a'] += 1;
            }
            for (; ptr<n; ptr+=sublen) {
                cnt1.assign(26,0);
                for (int i=0; i<sublen; i++) {
                    cnt1[s[ptr+i]-'a'] += 1;
                }
                if (cnt1!=cnt0) {
                    return false;
                }
            }
            return true;
        };
        for (int i=1; i<=n-1; i++) {
            if (!(n%i) and isValid(i))
                return i;
        }
        return n;
    }

    // 怎么会有这么简单直白粗暴的枚举啊啊啊啊啊啊啊啊
    // 我按照分解质因数和二分枚举想了好久 tmd
};
// @lc code=end

int main(void) {

}

/*
// @lcpr case=start
// "abba"\n
// @lcpr case=end

// @lcpr case=start
// "cdef"\n
// @lcpr case=end

 */

