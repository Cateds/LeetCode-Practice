/*
 * @lc app=leetcode.cn id=1338 lang=cpp
 * @lcpr version=30204
 *
 * [1338] 数组大小减半
 *
 * https://leetcode.cn/problems/reduce-array-size-to-the-half/description/
 *
 * algorithms
 * Medium (65.79%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    16.8K
 * Total Submissions: 25.4K
 * Testcase Example:  '[3,3,3,3,5,5,5,2,2,7]'
 *
 * 给你一个整数数组 arr。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。
 *
 * 返回 至少 能删除数组中的一半整数的整数集合的最小大小。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = [3,3,3,3,5,5,5,2,2,7]
 * 输出：2
 * 解释：选择 {3,7} 使得结果数组为 [5,5,5,2,2]、长度为 5（原数组长度的一半）。
 * 大小为 2 的可行集合有 {3,5},{3,2},{5,2}。
 * 选择 {2,7} 是不可行的，它的结果数组为 [3,3,3,3,5,5,5]，新数组长度大于原数组的二分之一。
 *
 *
 * 示例 2：
 *
 * 输入：arr = [7,7,7,7,7,7]
 * 输出：1
 * 解释：我们只能选择集合 {7}，结果数组为空。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 10^5
 * arr.length 为偶数
 * 1 <= arr[i] <= 10^5
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
#include <ranges>
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
    int minSetSize(vector<int> &arr) {
        unordered_map<int, int> mp;
        for (auto &n : arr)
            mp[n] += 1;
        priority_queue<int> cnt;
        for (auto &[_,val]: mp) cnt.push(val);
        int n = (arr.size()+1)/2;
        int ans = 0, ansVal = 0;
        do {
            ans ++;
            ansVal += cnt.top();
            cnt.pop();
        } while (ansVal < n);
        return ans;
    }
};
// @lc code=end


/*
// @lcpr case=start
// [3,3,3,3,5,5,5,2,2,7]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7]\n
// @lcpr case=end

 */
