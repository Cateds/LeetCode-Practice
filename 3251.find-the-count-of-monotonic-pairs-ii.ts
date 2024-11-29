/*
 * @lc app=leetcode.cn id=3251 lang=typescript
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
 * Total Accepted:    4.3K
 * Total Submissions: 8.2K
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

// @lc code=start
// 为什么同一个东西我的typescript跑出来内存和效率都比C++好
// 真有点破防了
function countOfPairs(nums: number[]): number {
    let n = nums.length;
    let prv: number[] = [];
    let cur: number[] = new Array(nums[0]+1).fill(1);
    let ans = 0;
    for (let i=1; i<n; i++) {
        prv = cur;
        cur = new Array(nums[i]+1).fill(0);
        let shift = 0;
        if (nums[i-1]-nums[i] <0) shift = nums[i-1]-nums[i];
        let sum = 0;
        for (let j = -shift; j<=nums[i]; j++) {
            sum = (prv[j+shift]+sum)%(1000000000+7);
            cur[j] = sum;
        }
    }
    for (let d of cur)
        ans = (ans + d)%(1000000000+7);
    return ans;
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

 */

