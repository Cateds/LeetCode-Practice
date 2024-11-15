/*
 * @lc app=leetcode.cn id=3261 lang=cpp
 * @lcpr version=30204
 *
 * [3261] 统计满足 K 约束的子字符串数量 II
 *
 * https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-ii/description/
 *
 * algorithms
 * Hard (41.29%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    2.2K
 * Total Submissions: 4.9K
 * Testcase Example:  '"0001111"\n2\n[[0,6]]'
 *
 * 给你一个 二进制 字符串 s 和一个整数 k。
 *
 * 另给你一个二维整数数组 queries ，其中 queries[i] = [li, ri] 。
 *
 * 如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：
 *
 *
 * 字符串中 0 的数量最多为 k。
 * 字符串中 1 的数量最多为 k。
 *
 *
 * 返回一个整数数组 answer ，其中 answer[i] 表示 s[li..ri] 中满足 k 约束 的 子字符串 的数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "0001111", k = 2, queries = [[0,6]]
 *
 * 输出：[26]
 *
 * 解释：
 *
 * 对于查询 [0, 6]， s[0..6] = "0001111" 的所有子字符串中，除 s[0..5] = "000111" 和 s[0..6] =
 * "0001111" 外，其余子字符串都满足 k 约束。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]
 *
 * 输出：[15,9,3]
 *
 * 解释：
 *
 * s 的所有子字符串中，长度大于 3 的子字符串都不满足 k 约束。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] 是 '0' 或 '1'
 * 1 <= k <= s.length
 * 1 <= queries.length <= 10^5
 * queries[i] == [li, ri]
 * 0 <= li <= ri < s.length
 * 所有查询互不相同
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
    vector<long long> countKConstraintSubstrings(
        string &s, const int &k, vector<vector<int>> &queries) {
        unsigned n = s.length();
        vector<long long> ans;
        vector<unsigned> right(n + 1, n);
        vector<long long> pfx(n + 1);
        unsigned cnt[2];
        cnt[s[0] - '0']++;
        unsigned l = 0, r = 1;
        while (true) {
            if (cnt[0] <= k or cnt[1] <= k) {
                pfx[r] = pfx[r - 1] + r - l;
                if (r == n)
                    break;
                cnt[s[r++] - '0']++;
            } else {
                right[l] = r-1;
                cnt[s[l++] - '0']--;
            }
        }
        // for (int i = 0; i <= n; i++) {
        //     cout << format("{:d}: {:d} {:d}",
        //                    i, right[i], pfx[i]) << endl;
        // }
        for (auto &qr : queries) {
            auto len = qr[1] - qr[0];
            long long tmp;
            if (right[qr[0]] > qr[1]) {
                tmp = (long long)(len + 1) * (len + 2) / 2;
            } else {
                auto sublen = right[qr[0]] - qr[0];
                tmp = (long long)sublen * (sublen + 1) / 2;
                tmp += pfx[qr[1] + 1] - pfx[right[qr[0]]];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "0001111"\n2\n[[0,5]]\n
// @lcpr case=end

// @lcpr case=start
// "010101"\n1\n[[0,5],[1,4],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// "00"\n1\n[[0,0],[0,1],[1,1]]\n
// @lcpr case=end
 */
