// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=997 lang=cpp
 * @lcpr version=30204
 *
 * [997] 找到小镇的法官
 *
 * https://leetcode.cn/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (51.55%)
 * Likes:    359
 * Dislikes: 0
 * Total Accepted:    113.9K
 * Total Submissions: 218.6K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * 小镇里有 n 个人，按从 1 到 n 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。
 * 
 * 如果小镇法官真的存在，那么：
 * 
 * 
 * 小镇法官不会信任任何人。
 * 每个人（除了小镇法官）都信任这位小镇法官。
 * 只有一个人同时满足属性 1 和属性 2 。
 * 
 * 
 * 给你一个数组 trust ，其中 trust[i] = [ai, bi] 表示编号为 ai 的人信任编号为 bi 的人。
 * 
 * 如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 2, trust = [[1,2]]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 3, trust = [[1,3],[2,3]]
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 3, trust = [[1,3],[2,3],[3,1]]
 * 输出：-1
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 1000
 * 0 <= trust.length <= 10^4
 * trust[i].length == 2
 * trust 中的所有trust[i] = [ai, bi] 互不相同
 * ai != bi
 * 1 <= ai, bi <= n
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
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> beTrusted(n,0);
        vector<int> trustOth(n,0);
        for (auto &Link: trust) {
            trustOth[Link[0]-1] += 1;
            beTrusted[Link[1]-1] += 1;
        }
        int ans = -1;
        for (int i=0; i<n; i++) {
            if (trustOth[i] == 0 and beTrusted[i] == n-1) {
                if (ans == -1) ans = i+1;
                else return -1;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,3],[2,3],[3,1]]\n
// @lcpr case=end

 */

