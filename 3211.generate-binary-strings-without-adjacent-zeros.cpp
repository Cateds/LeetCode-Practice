// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3211 lang=cpp
 * @lcpr version=30204
 *
 * [3211] 生成不含相邻零的二进制字符串
 *
 * https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/description/
 *
 * algorithms
 * Medium (83.29%)
 * Likes:    30
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 20.7K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n。
 * 
 * 如果一个二进制字符串 x 的所有长度为 2 的子字符串中包含 至少 一个 "1"，则称 x 是一个 有效 字符串。
 * 
 * 返回所有长度为 n 的 有效 字符串，可以以任意顺序排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： n = 3
 * 
 * 输出： ["010","011","101","110","111"]
 * 
 * 解释：
 * 
 * 长度为 3 的有效字符串有："010"、"011"、"101"、"110" 和 "111"。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： n = 1
 * 
 * 输出： ["0","1"]
 * 
 * 解释：
 * 
 * 长度为 1 的有效字符串有："0" 和 "1"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 18
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
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp;
        auto dfs = 
        [&](auto f) -> void {
            if (temp.size()==n) {
                ans.push_back(temp);
                return;
            }
            if (temp.empty() or temp.back()-'0') {
                temp.push_back('1');
                f(f);
                temp.back()='0';
                f(f);
                temp.pop_back();
            }
            else {
                temp.push_back('1');
                f(f);
                temp.pop_back();
            }
        };
        dfs(dfs);
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=validStrings
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

