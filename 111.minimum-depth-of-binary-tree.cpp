/*
 * @lc app=leetcode.cn id=111 lang=cpp
 * @lcpr version=30204
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (54.93%)
 * Likes:    1236
 * Dislikes: 0
 * Total Accepted:    747.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明：叶子节点是指没有子节点的节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000 <= Node.val <= 1000
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
    // 层序遍历
    int minDepth(TreeNode* root) {
        if (root==nullptr)
            return 0;
        list<pair<TreeNode*,uint16_t>> todo;
        todo.push_back({root,1});
        uint8_t cnt = 0;
        do {
            auto &[p,n] = todo.front();
            cnt = 0;
            if (p->left==nullptr) cnt++;
            else todo.push_back({p->left,n+1});
            if (p->right==nullptr) cnt++;
            else todo.push_back({p->right,n+1});
            if (cnt == 2) return n;
            todo.pop_front();
        } while (true);
    }
    
    // // DFS
    // int minDepth(TreeNode* root) {
    //     if (root==nullptr)
    //         return 0;
    //     auto dfs =
    //     [&](auto dfs, TreeNode *&ptr, int &&depth) {
    //         if (ptr==nullptr)
    //             return INT_MAX;
    //         else if (ptr->left==nullptr and ptr->right==nullptr)
    //             return depth;
    //         else
    //             return min(
    //                 dfs(dfs, ptr->left, depth+1),
    //                 dfs(dfs, ptr->right, depth+1)
    //             );
    //     };
    //     return dfs(dfs,root,1);
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,null,3,null,4,null,5,null,6]\n
// @lcpr case=end

 */

