/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=30204
 *
 * [337] 打家劫舍 III
 *
 * https://leetcode.cn/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (61.83%)
 * Likes:    2020
 * Dislikes: 0
 * Total Accepted:    374.4K
 * Total Submissions: 605.4K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
 * 
 * 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果
 * 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
 * 
 * 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入: root = [3,2,3,null,3,null,1]
 * 输出: 7 
 * 解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
 * 
 * 示例 2:
 * 
 * 
 * 
 * 输入: root = [3,4,5,1,3,null,1]
 * 输出: 9
 * 解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 树的节点数在 [1, 10^4] 范围内
 * 0 <= Node.val <= 10^4
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
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int rob(TreeNode* root) {
        auto dfs =
        [&](auto dfs, TreeNode *&ptr) {
            if (ptr==nullptr) 
                return pair<int,int> {0,0};
            pair<int,int> lpr = dfs(dfs, ptr->left);
            pair<int,int> rpr = dfs(dfs, ptr->right);
            return pair<int,int> {
                lpr.second + rpr.second + ptr->val,
                max(lpr.first, lpr.second) + 
                max(rpr.first, rpr.second)
            };
        };
        auto result = dfs(dfs, root);
        return max(result.first, result.second);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */

