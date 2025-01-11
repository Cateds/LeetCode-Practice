/*
 * @lc app=leetcode.cn id=3254 lang=cpp
 * @lcpr version=30204
 *
 * [3254] 长度为 K 的子数组的能量值 I
 *
 * https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-i/description/
 *
 * algorithms
 * Medium (51.36%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 6.4K
 * Testcase Example:  '[1,2,3,4,3,2,5]\n3'
 *
 * 给你一个长度为 n 的整数数组 nums 和一个正整数 k 。
 * 
 * 一个数组的 能量值 定义为：
 * 
 * 
 * 如果 所有 元素都是依次 连续 且 上升 的，那么能量值为 最大 的元素。
 * 否则为 -1 。
 * 
 * 
 * 你需要求出 nums 中所有长度为 k 的 子数组 的能量值。
 * 
 * 请你返回一个长度为 n - k + 1 的整数数组 results ，其中 results[i] 是子数组 nums[i..(i + k - 1)]
 * 的能量值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,4,3,2,5], k = 3
 * 
 * 输出：[3,4,-1,-1,-1]
 * 
 * 解释：
 * 
 * nums 中总共有 5 个长度为 3 的子数组：
 * 
 * 
 * [1, 2, 3] 中最大元素为 3 。
 * [2, 3, 4] 中最大元素为 4 。
 * [3, 4, 3] 中元素 不是 连续的。
 * [4, 3, 2] 中元素 不是 上升的。
 * [3, 2, 5] 中元素 不是 连续的。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2,2,2], k = 4
 * 
 * 输出：[-1,-1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [3,2,3,2,3,2], k = 2
 * 
 * 输出：[-1,3,-1,3,-1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == nums.length <= 500
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= n
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
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k==1)
            return nums;
        unsigned int toBeAsc = 0;
        unsigned int n = nums.size();
        vector<int> ans(n-k+1);
        unsigned int p;
        for (p=1; p<k; p++) {
            if (nums[p]!=nums[p-1]+1) {
                toBeAsc=p;
            }
        }
        ans[0] = toBeAsc ? -1 : nums[k-1];
        for (; p<n; p++) {
            if (nums[p]==nums[p-1]+1) {
                if (toBeAsc)
                    toBeAsc -= 1;
                if (toBeAsc) 
                    ans[p-k+1] = -1;
                else
                    ans[p-k+1] = nums[p];
            }
            else {
                toBeAsc = k-1;
                ans[p-k+1] = -1;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,3,2,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,2,3,2]\n2\n
// @lcpr case=end

 */

