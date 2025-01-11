/*
 * @lc app=leetcode.cn id=2956 lang=cpp
 * @lcpr version=30204
 *
 * [2956] 找到两个数组中的公共元素
 *
 * https://leetcode.cn/problems/find-common-elements-between-two-arrays/description/
 *
 * algorithms
 * Easy (80.12%)
 * Likes:    32
 * Dislikes: 0
 * Total Accepted:    23.8K
 * Total Submissions: 27.6K
 * Testcase Example:  '[2,3,2]\n[1,2]'
 *
 * 给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，它们分别含有 n 和 m 个元素。请你计算以下两个数值：
 * 
 * 
 * answer1：使得 nums1[i] 在 nums2 中出现的下标 i 的数量。
 * answer2：使得 nums2[i] 在 nums1 中出现的下标 i 的数量。
 * 
 * 
 * 返回 [answer1, answer2]。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [2,3,2], nums2 = [1,2]
 * 
 * 输出：[2,1]
 * 
 * 解释：
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]
 * 
 * 输出：[3,4]
 * 
 * 解释：
 * 
 * nums1 中下标在 1，2，3 的元素在 nums2 中也存在。所以 answer1 为 3。
 * 
 * nums2 中下标在 0，1，3，4 的元素在 nums1 中也存在。所以 answer2 为 4。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums1 = [3,4,2,3], nums2 = [1,5]
 * 
 * 输出：[0,0]
 * 
 * 解释：
 * 
 * nums1 和 nums2 中没有相同的数字，所以答案是 [0,0]。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums1.length
 * m == nums2.length
 * 1 <= n, m <= 100
 * 1 <= nums1[i], nums2[i] <= 100
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
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> retVal(2);
        unordered_set<int> 
            Set1(nums1.begin(),nums1.end()),
            Set2(nums2.begin(),nums2.end());
        for (auto &num: nums2) {
            retVal[1] += Set1.count(num)>0;
        }
        for (auto &num: nums1) {
            retVal[0] += Set2.count(num)>0;
        }
        return retVal;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n[1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,3,1]\n[2,2,5,2,3,6]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,2,3]\n[1,5]\n
// @lcpr case=end

 */

