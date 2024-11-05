// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3181 lang=cpp
 * @lcpr version=30204
 *
 * [3181] 执行操作可获得的最大总奖励 II
 *
 * https://leetcode.cn/problems/maximum-total-reward-using-operations-ii/description/
 *
 * algorithms
 * Hard (34.26%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 12.2K
 * Testcase Example:  '[1,1,3,3]'
 *
 * 给你一个整数数组 rewardValues，长度为 n，代表奖励的值。
 *
 * 最初，你的总奖励 x 为 0，所有下标都是 未标记 的。你可以执行以下操作 任意次 ：
 *
 *
 * 从区间 [0, n - 1] 中选择一个 未标记 的下标 i。
 * 如果 rewardValues[i] 大于 你当前的总奖励 x，则将 rewardValues[i] 加到 x 上（即 x = x +
 * rewardValues[i]），并 标记 下标 i。
 *
 *
 * 以整数形式返回执行最优操作能够获得的 最大 总奖励。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：rewardValues = [1,1,3,3]
 *
 * 输出：4
 *
 * 解释：
 *
 * 依次标记下标 0 和 2，总奖励为 4，这是可获得的最大值。
 *
 *
 * 示例 2：
 *
 *
 * 输入：rewardValues = [1,6,4,3,2]
 *
 * 输出：11
 *
 * 解释：
 *
 * 依次标记下标 0、2 和 1。总奖励为 11，这是可获得的最大值。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= rewardValues.length <= 5 * 10^4
 * 1 <= rewardValues[i] <= 5 * 10^4
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
    int maxTotalReward(vector<int> &rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        if (rewardValues.size() >= 2 
            and rewardValues.end()[-1] - 1 == rewardValues.end()[-2])
            return rewardValues.end()[-1] * 2 - 1;
        bitset<100000> bs(1), mk(0);
        auto size = bs.size();
        for (long i=0,j=0; i<rewardValues.size(); i++) {
            while (j<rewardValues[i]) {
                mk[j] = bs[j];
                j++;
            }
            bs |= (mk << rewardValues[i]);
        }
        for (unsigned i = rewardValues.back() * 2 - 1;; i--) {
            if (bs[i])
                return i;
        }
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxTotalReward
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,1,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,6,4,3,2]\n
// @lcpr case=end

 */
