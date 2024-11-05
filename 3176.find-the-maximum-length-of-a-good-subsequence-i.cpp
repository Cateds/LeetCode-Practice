/*
 * @lc app=leetcode.cn id=3176 lang=cpp
 * @lcpr version=30204
 *
 * [3176] 求出最长好子序列 I
 *
 * https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-i/description/
 *
 * algorithms
 * Medium (31.07%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 23K
 * Testcase Example:  '[1,2,1,1,3]\n2'
 *
 * 给你一个整数数组 nums 和一个 非负 整数 k 。如果一个整数序列 seq 满足在下标范围 [0, seq.length - 2] 中 最多只有 k
 * 个下标 i 满足 seq[i] != seq[i + 1] ，那么我们称这个整数序列为 好 序列。
 * 
 * 请你返回 nums 中 好 子序列 的最长长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,1,1,3], k = 2
 * 
 * 输出：4
 * 
 * 解释：
 * 
 * 最长好子序列为 [1,2,1,1,3] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4,5,1], k = 0
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 最长好子序列为 [1,2,3,4,5,1] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 500
 * 1 <= nums[i] <= 10^9
 * 0 <= k <= min(nums.length, 25)
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
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        int len = nums.size();
        vector<vector<int>> dp;
        dp.resize(len, vector<int>(51, -1));
        for (int i = 0; i < len; i++) {
            dp[i][0] = 1;
            for (int l = 0; l <= k; l++) {
                for (int j = 0; j < i; j++) {
                    int add = (nums[i] != nums[j]);
                    if (l - add >= 0 && dp[j][l - add] != -1) {
                        dp[i][l] = max(dp[i][l], dp[j][l - add] + 1);
                    }
                }
                ans = max(ans, dp[i][l]);
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,1]\n0\n
// @lcpr case=end

 */

