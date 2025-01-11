/*
 * @lc app=leetcode.cn id=1547 lang=cpp
 * @lcpr version=30204
 *
 * [1547] 切棍子的最小成本
 *
 * https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/description/
 *
 * algorithms
 * Hard (58.84%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 16.6K
 * Testcase Example:  '7\n[1,3,4,5]'
 *
 * 有一根长度为 n 个单位的木棍，棍上从 0 到 n 标记了若干位置。例如，长度为 6 的棍子可以标记如下：
 *
 *
 *
 * 给你一个整数数组 cuts ，其中 cuts[i] 表示你需要将棍子切开的位置。
 *
 * 你可以按顺序完成切割，也可以根据需要更改切割的顺序。
 *
 *
 * 每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。对棍子进行切割将会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前木棍的长度）。请参阅第一个示例以获得更直观的解释。
 *
 * 返回切棍子的 最小总成本 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：n = 7, cuts = [1,3,4,5]
 * 输出：16
 * 解释：按 [1, 3, 4, 5] 的顺序切割的情况如下所示：
 *
 * 第一次切割长度为 7 的棍子，成本为 7 。第二次切割长度为 6 的棍子（即第一次切割得到的第二根棍子），第三次切割为长度 4 的棍子，最后切割长度为
 * 3 的棍子。总成本为 7 + 6 + 4 + 3 = 20 。
 * 而将切割顺序重新排列为 [3, 5, 1, 4] 后，总成本 = 16（如示例图中 7 + 4 + 3 + 2 = 16）。
 *
 *
 * 示例 2：
 *
 * 输入：n = 9, cuts = [5,6,1,4,2]
 * 输出：22
 * 解释：如果按给定的顺序切割，则总成本为 25 。总成本 <= 25 的切割顺序很多，例如，[4, 6, 5, 2, 1] 的总成本 =
 * 22，是所有可能方案中成本最小的。
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 10^6
 * 1 <= cuts.length <= min(n - 1, 100)
 * 1 <= cuts[i] <= n - 1
 * cuts 数组中的所有整数都 互不相同
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
    // // 想着按照霍夫曼的方法造树结果狗屁不通（
    // int minCost(const int &n, vector<int> &cuts) {
    //     int ans = 0;
    //     if (cuts.size() == 1)
    //         return n;
    //     vector<int> parts(cuts.size() + 1);
    //     cuts.push_back(0);
    //     cuts.push_back(n);
    //     sort(cuts.begin(), cuts.end());
    //     for (int i = 0; i < parts.size(); i++) {
    //         parts[i] = cuts[i + 1] - cuts[i];
    //     }
    //     while (parts.size() != 1) {
    //         int posi = 0;
    //         for (int i = 1; i < parts.size() - 1; i++)
    //             if (parts[posi] + parts[posi + 1] > parts[i] + parts[i + 1])
    //                 posi = i;
    //         parts[posi] += parts[posi + 1];
    //         ans += parts[posi];
    //         parts.erase(parts.begin() + posi + 1);
    //     }
    //     return ans;
    // }

    int minCost(const int &n, vector<int> &cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size() - 1);
        int size = cuts.size() - 1;
        dp.front().resize(size);
        for (int t = 1; t < size; t++) {
            dp[t].resize(size - t);
            for (int i = 0; i < size - t; i++) {
                dp[t][i] = INT_MAX;
                for (int j = 1; j < t + 1; j++)
                    dp[t][i] = min(
                        dp[t][i],
                        dp[j - 1][i] + dp[t - j][i + j] 
                        + cuts[i + t + 1] - cuts[i]);
            }
        }
        return dp.back().front();
    }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n[1,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// 36\n[13,17,15,18,3,22,27,6,35,7,11,28,26,20,4,5,21,10,8]\n
// @lcpr case=end

// @lcpr case=start
// 9\n[5,6,1,4,2]\n
// @lcpr case=end

 */
