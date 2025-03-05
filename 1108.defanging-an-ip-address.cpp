/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 * @lcpr version=30204
 *
 * [1108] IP 地址无效化
 *
 * https://leetcode.cn/problems/defanging-an-ip-address/description/
 *
 * algorithms
 * Easy (85.25%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    126.3K
 * Total Submissions: 148.1K
 * Testcase Example:  '"1.1.1.1"'
 *
 * 给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
 *
 * 所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。
 *
 *
 *
 * 示例 1：
 *
 * 输入：address = "1.1.1.1"
 * 输出："1[.]1[.]1[.]1"
 *
 *
 * 示例 2：
 *
 * 输入：address = "255.100.50.0"
 * 输出："255[.]100[.]50[.]0"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给出的 address 是一个有效的 IPv4 地址
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
#include <ranges>
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
    string defangIPaddr(string address) {
        string ans;
        for (auto &ch : address) {
            if (ch == '.')
                ans += "[.]";
            else
                ans += ch;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "1.1.1.1"\n
// @lcpr case=end

// @lcpr case=start
// "255.100.50.0"\n
// @lcpr case=end

 */
