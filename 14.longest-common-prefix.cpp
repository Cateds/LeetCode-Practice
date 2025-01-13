/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30204
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (44.54%)
 * Likes:    3249
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.2M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 *
 *
 * 示例 1：
 *
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 *
 *
 * 示例 2：
 *
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 如果非空，则仅由小写英文字母组成
 *
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        int Res = strs[0].length();
        for (int i = 1; i < n; i++) {
            if (strs[i].length() < Res)
                Res = strs[i].length();
            for (int j = 0; j < Res; j++) {
                if (strs[0][j] == strs[i][j])
                    continue;
                else {
                    Res = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, Res);
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */
