/*
 * @lc app=leetcode.cn id=852 lang=cpp
 * @lcpr version=30204
 *
 * [852] 山脉数组的峰顶索引
 *
 * https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Medium (68.33%)
 * Likes:    416
 * Dislikes: 0
 * Total Accepted:    173.1K
 * Total Submissions: 253.4K
 * Testcase Example:  '[0,1,0]'
 *
 * 给定一个长度为 n 的整数 山脉 数组 arr ，其中的值递增到一个 峰值元素 然后递减。
 *
 * 返回峰值元素的下标。
 *
 * 你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = [0,1,0]
 * 输出：1
 *
 *
 * 示例 2：
 *
 * 输入：arr = [0,2,1,0]
 * 输出：1
 *
 *
 * 示例 3：
 *
 * 输入：arr = [0,10,5,2]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= arr.length <= 10^5
 * 0 <= arr[i] <= 10^6
 * 题目数据 保证 arr 是一个山脉数组
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
    int peakIndexInMountainArray(vector<int> &arr) {
        uint32_t l = 0, r = arr.size();
        while (true) {
            if (l + 1 >= r)
                break;
            auto i = (l + r) / 2;
            if ((long)(arr[i]-arr[i-1])*(arr[i+1]-arr[i])<0)
                return i;
            else if (arr[i]-arr[i-1]>0) 
                l=i+1;
            else
                r=i;
        }
        return l;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,10,5,2]\n
// @lcpr case=end

 */
