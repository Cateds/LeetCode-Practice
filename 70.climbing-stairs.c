/*
 * @lc app=leetcode.cn id=70 lang=c
 * @lcpr version=30113
 *
 * [70] 爬楼梯
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
int climbStairs(int n) 
{
    int n1 = 1,n2 = 1;
    for (int i=2; i<=n; i++) {
        int temp = n1 + n2;
        n1 = n2;
        n2 = temp;
    }
    return n2;
}
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

