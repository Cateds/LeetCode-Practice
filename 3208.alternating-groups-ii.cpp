/*
 * @lc app=leetcode.cn id=3208 lang=cpp
 * @lcpr version=30204
 *
 * [3208] 交替组 II
 *
 * https://leetcode.cn/problems/alternating-groups-ii/description/
 *
 * algorithms
 * Medium (48.04%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    15.7K
 * Total Submissions: 25.8K
 * Testcase Example:  '[0,1,0,1,0]\n3'
 *
 * 给你一个整数数组 colors 和一个整数 k ，colors表示一个由红色和蓝色瓷砖组成的环，第 i 块瓷砖的颜色为 colors[i]
 * ：
 *
 *
 * colors[i] == 0 表示第 i 块瓷砖的颜色是 红色 。
 * colors[i] == 1 表示第 i 块瓷砖的颜色是 蓝色 。
 *
 *
 * 环中连续 k 块瓷砖的颜色如果是 交替 颜色（也就是说除了第一块和最后一块瓷砖以外，中间瓷砖的颜色与它 左边 和 右边 的颜色都不同），那么它被称为一个
 * 交替 组。
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
 * 输入：colors = [0,1,0,1,0], k = 3
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
 * 示例 2：
 *
 *
 * 输入：colors = [0,1,0,0,1,0,1], k = 6
 *
 * 输出：2
 *
 * 解释：
 *
 *
 *
 * 交替组包括：
 *
 *
 *
 * 示例 3：
 *
 * 输入：colors = [1,1,0,1], k = 4
 *
 * 输出：0
 *
 * 解释：
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= colors.length <= 10^5
 * 0 <= colors[i] <= 1
 * 3 <= k <= colors.length
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
    // // 前缀和
    // // 为什么我会想着写前缀和？
    // int numberOfAlternatingGroups(vector<int> &colors, const int &k) {
    //     int ans = 0;
    //     uint32_t n = colors.size();
    //     vector<uint32_t> pfx(n+1);
    //     pfx[0] = 0;
    //     pfx[1] = colors[0]!=colors[1];
    //     for (uint32_t i=1; i<n-1; i++)
    //         pfx[i+1] = pfx[i] + (colors[i]!=colors[i+1]);
    //     pfx[n] = pfx[n-1] + (colors.back()!=colors.front());
    //     uint32_t l=0, r=k-1;
    //     while (r<=n)
    //         if (pfx[r++]-pfx[l++]==k-1) ans++;
    //     for (r=1; r<k-1; r++)
    //         if (pfx[r]+pfx.back()-pfx[l++]==k-1) ans++;
    //     return ans;
    // }

    // 模拟
    int numberOfAlternatingGroups(vector<int>& colors, 
                                  int k) {
        uint32_t n = colors.size();
        uint32_t ans = 0;
        uint32_t cnt = k-1;
        for (uint32_t i=0; i<n+k-2; i++) {
            if (colors[i%n]!=colors[(i+1)%n]) {
                if (cnt) cnt--;
                if (!cnt) ans++;
            } else cnt = k-1;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,1,0]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,0,1,0,1]\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,1]\n4\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,1]\n4\n
// @lcpr case=end

 */
