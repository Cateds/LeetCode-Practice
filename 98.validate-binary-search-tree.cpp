/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30204
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (38.61%)
 * Likes:    2459
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 * 有效 二叉搜索树定义如下：
 *
 *
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [2,1,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    // // DFS
    // bool isValidBST(TreeNode *&root) {
    //     if (root == nullptr)
    //         return true;
    //     bool isValid = true;
    //     auto dfs =
    //         [&](auto &dfs, TreeNode *&p,
    //             const long &l, const long &r) {
    //             if (p == nullptr)
    //                 return;
    //             if (p->val <= l or p->val >= r) {
    //                 isValid = false;
    //                 return;
    //             }
    //             dfs(dfs, p->left, l, p->val);
    //             if (!isValid)
    //                 return;
    //             dfs(dfs, p->right, p->val, r);
    //         };
    //     dfs(dfs, root, LONG_MIN, LONG_MAX);
    //     return isValid;
    // }

    // BFS
    bool isValidBST(TreeNode *&root) {
        if (root == nullptr)
            return true;
        struct listNode {
            TreeNode *p;
            long l;
            long r;
        };
        queue<listNode> bfs;
        bfs.push({root, LONG_MIN, LONG_MAX});
        while (!bfs.empty()) {
            auto &n = bfs.front();
            uint8_t cnt = 0;
            if (n.p->left != nullptr) {
                if (n.p->left->val >= n.p->val or
                    n.p->left->val <= n.l)
                    return false;
                bfs.push({n.p->left, n.l, n.p->val});
            }
            if (n.p->right != nullptr) {
                if (n.p->right->val <= n.p->val or
                    n.p->right->val >= n.r)
                    return false;
                bfs.push({n.p->right, n.p->val, n.r});
            }
            bfs.pop();
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */
