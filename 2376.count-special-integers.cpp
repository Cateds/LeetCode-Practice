/*
 * @lc app=leetcode.cn id=2376 lang=cpp
 * @lcpr version=30204
 *
 * [2376] 统计特殊整数
 *
 * https://leetcode.cn/problems/count-special-integers/description/
 *
 * algorithms
 * Hard (57.35%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    19K
 * Total Submissions: 32.8K
 * Testcase Example:  '20'
 *
 * 如果一个正整数每一个数位都是 互不相同 的，我们称它是 特殊整数 。
 * 
 * 给你一个 正 整数 n ，请你返回区间 [1, n] 之间特殊整数的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 20
 * 输出：19
 * 解释：1 到 20 之间所有整数除了 11 以外都是特殊整数。所以总共有 19 个特殊整数。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 5
 * 输出：5
 * 解释：1 到 5 所有整数都是特殊整数。
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 135
 * 输出：110
 * 解释：从 1 到 135 总共有 110 个整数是特殊整数。
 * 不特殊的部分数字为：22 ，114 和 131 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2 * 10^9
 * 
 * 
 */


// @lcpr-template-start
// #include <cmath>
#include <math.h>
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
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int countSpecialNumbers(int n) {
        int digit_num = floor(log10(n))+1;
        int ans = 0;
        for (int i=0, toAdd=1; i<digit_num-1; i++) {
            toAdd *= (10-i-(i==0));
            ans += toAdd;
        }
        vector<char> digits(digit_num);
        for (auto i=0; i<digit_num; i++,n/=10)
            digits[digit_num-1-i] = n%10;
        bool isUsed[10] = {0};
        function<int(const int &, bool)> dfs = 
        [&dfs,&digits,&isUsed,&digit_num](const int & rank, bool flag) -> int {
            if (rank == digit_num) return 1;
            int ans = 0;
            for (int i=(rank==0); i<=(flag ? digits[rank] : 9); i++) {
                if (isUsed[i]) continue;
                isUsed[i] = true;
                ans += dfs(rank+1,flag and i==digits[rank]);
                isUsed[i] = false;
            }
            return ans;
        };
        return ans + dfs(0,true);
    }
};
// @lc code=end

// Input 1581 Output 1005
int main(void) {
    Solution sln;
    cout << sln.countSpecialNumbers(1581);
}

/*
// @lcpr case=start
// 20\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 135\n
// @lcpr case=end

 */

