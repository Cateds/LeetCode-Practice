// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3206 lang=cpp
 * @lcpr version=30204
 *
 * [3206] 交替组 I
 *
 * https://leetcode.cn/problems/alternating-groups-i/description/
 *
 * algorithms
 * Easy (71.02%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    5K
 * Total Submissions: 6.9K
 * Testcase Example:  '[1,1,1]'
 *
 * 给你一个整数数组 colors ，它表示一个由红色和蓝色瓷砖组成的环，第 i 块瓷砖的颜色为 colors[i] ：
 *
 *
 * colors[i] == 0 表示第 i 块瓷砖的颜色是 红色 。
 * colors[i] == 1 表示第 i 块瓷砖的颜色是 蓝色 。
 *
 *
 * 环中连续 3 块瓷砖的颜色如果是 交替 颜色（也就是说中间瓷砖的颜色与它 左边 和 右边 的颜色都不同），那么它被称为一个 交替 组。
 *
 * 请你返回 交替 组的数目。
 *
 * 注意 ，由于 colors 表示一个 环 ，第一块 瓷砖和 最后一块 瓷砖是相邻的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：colors = [1,1,1]
 *
 * 输出：0
 *
 * 解释：
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：colors = [0,1,0,0,1]
 *
 * 输出：3
 *
 * 解释：
 *
 *
 *
 * 交替组包括：
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= colors.length <= 100
 * 0 <= colors[i] <= 1
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
    // // method 1
    // int numberOfAlternatingGroups(vector<int>& colors) {
    //     bool prevIsInverted = colors.back()!=colors.front();
    //     bool isInverted;
    //     uint8_t ans = 0;
    //     for (int i=0; i<colors.size()-1; i++) {
    //         isInverted = colors[i]!=colors[i+1];
    //         ans += isInverted and prevIsInverted;
    //         prevIsInverted = isInverted;
    //     }
    //     return ans + (prevIsInverted and colors.back()!=colors.front());
    // }
    
    // method 2
    int numberOfAlternatingGroups(vector<int> &colors) {
        uint8_t ans = colors.back()!=colors.front() and colors[0]!=colors[1];
        ans += colors.back()!=colors.front() and colors.end()[-1]!=colors.end()[-2];
        for (int i=1; i<colors.size()-1; i++)
            ans += colors[i-1]!=colors[i] and colors[i]!=colors[i+1];
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=numberOfAlternatingGroups
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,0,1]\n
// @lcpr case=end

 */
