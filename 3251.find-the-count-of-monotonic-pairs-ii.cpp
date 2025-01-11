/*
 * @lc app=leetcode.cn id=3251 lang=cpp
 * @lcpr version=30204
 *
 * [3251] 单调数组对的数目 II
 *
 * https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-ii/description/
 *
 * algorithms
 * Hard (47.58%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    4.2K
 * Total Submissions: 8.1K
 * Testcase Example:  '[2,3,2]'
 *
 * 给你一个长度为 n 的 正 整数数组 nums 。
 * 
 * 如果两个 非负 整数数组 (arr1, arr2) 满足以下条件，我们称它们是 单调 数组对：
 * 
 * 
 * 两个数组的长度都是 n 。
 * arr1 是单调 非递减 的，换句话说 arr1[0] <= arr1[1] <= ... <= arr1[n - 1] 。
 * arr2 是单调 非递增 的，换句话说 arr2[0] >= arr2[1] >= ... >= arr2[n - 1] 。
 * 对于所有的 0 <= i <= n - 1 都有 arr1[i] + arr2[i] == nums[i] 。
 * 
 * 
 * 请你返回所有 单调 数组对的数目。
 * 
 * 由于答案可能很大，请你将它对 10^9 + 7 取余 后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,2]
 * 
 * 输出：4
 * 
 * 解释：
 * 
 * 单调数组对包括：
 * 
 * 
 * ([0, 1, 1], [2, 2, 1])
 * ([0, 1, 2], [2, 2, 0])
 * ([0, 2, 2], [2, 1, 0])
 * ([1, 2, 2], [1, 1, 0])
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,5,5,5]
 * 
 * 输出：126
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == nums.length <= 2000
 * 1 <= nums[i] <= 1000
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
    // // dp
    // int countOfPairs(vector<int>& nums) {
    //     uint16_t n = nums.size();
    //     vector<vector<uint32_t>> dp;
    //     dp.push_back(vector<uint32_t>(nums.front()+1,1));
    //     for (uint16_t i=1; i<n; i++) {
    //         dp.push_back(vector<uint32_t>(nums[i]+1,0));
    //         int16_t shift = min(0, nums[i-1]-nums[i]);
    //         uint32_t sum = 0;
    //         for (uint16_t j=-shift; j<=nums[i]; j++) {
    //             sum = (dp[i-1][j+shift]+sum)%(1000000000+7);
    //             dp[i][j] = sum;
    //         }
    //     }
    //     uint32_t ans = 0;
    //     for (auto &d: dp.back())
    //         ans = (ans+d)%(1000000000+7);
    //     return ans;
    // }

    // 可能优化过内存使用的dp
    // 坏消息是几乎没有优化出任何的内存使用
    // 鉴定为没事找事干
    int countOfPairs(vector<int>& nums) {
        uint16_t n = nums.size();
        vector<uint32_t> prv;
        vector<uint32_t> cur(nums.front()+1,1);
        for (uint16_t i=1; i<n; i++) {
            prv = move(cur);
            cur.resize(nums[i]+1,0);
            uint16_t shift = max(0,nums[i]-nums[i-1]);
            uint32_t sum = 0;
            for (uint16_t j=shift; j<=nums[i]; j++) {
                sum = (prv[j-shift]+sum)%(1000000000+7);
                cur[j] = sum;
            }
        }
        uint32_t ans = 0;
        for (auto &d: cur)
            ans = (ans+d)%(1000000000+7);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,6,13]\n
// @lcpr case=end

 */

