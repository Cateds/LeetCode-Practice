/*
 * @lc app=leetcode.cn id=3177 lang=cpp
 * @lcpr version=30204
 *
 * [3177] 求出最长好子序列 II
 *
 * https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-ii/description/
 *
 * algorithms
 * Hard (36.95%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 16.9K
 * Testcase Example:  '[1,2,1,1,3]\n2'
 *
 * 给你一个整数数组 nums 和一个 非负 整数 k 。如果一个整数序列 seq 满足在范围下标范围 [0, seq.length - 2] 中存在
 * 不超过 k 个下标 i 满足 seq[i] != seq[i + 1] ，那么我们称这个整数序列为 好 序列。
 * 
 * 请你返回 nums 中 好 子序列 的最长长度
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
 * 1 <= nums.length <= 5 * 10^3
 * 1 <= nums[i] <= 10^9
 * 0 <= k <= min(50, nums.length)
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
        unordered_map<int, vector<int>> fs;
        vector<int> mx(k + 2);
        for (int x : nums) {
            auto& f = fs[x];
            f.resize(k + 1);
            for (int j = k; j >= 0; j--) {
                f[j] = max(f[j], mx[j]) + 1;
                mx[j + 1] = max(mx[j + 1], f[j]);
            }
        }
        return mx[k + 1];
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-ii/solutions/2805263/dong-tai-gui-hua-you-hua-pythonjavacgo-b-jqn2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。// @lc code=end



/*
// @lcpr case=start
// [1,2,1,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,1]\n0\n
// @lcpr case=end

 */

