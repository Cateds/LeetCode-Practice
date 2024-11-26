/*
 * @lc app=leetcode.cn id=109 lang=cpp
 * @lcpr version=30204
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (76.80%)
 * Likes:    922
 * Dislikes: 0
 * Total Accepted:    168.8K
 * Total Submissions: 219.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为 平衡 二叉搜索树。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入: head = [-10,-3,0,5,9]
 * 输出: [0,-3,9,-10,null,5]
 * 解释: 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
 *
 *
 * 示例 2:
 *
 * 输入: head = []
 * 输出: []
 *
 *
 *
 *
 * 提示:
 *
 *
 * head 中的节点数在[0, 2 * 10^4] 范围内
 * -10^5 <= Node.val <= 10^5
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        vector<ListNode *> nodes;
        for (auto p = head; p != nullptr; p = p->next)
            nodes.push_back(p);
        auto dfs =
            [&](auto &dfs, const int &start, const int &end) -> TreeNode * {
            if (end <= start)
                return nullptr;
            if (end - start == 1)
                return new TreeNode{nodes[start]->val};
            auto i = (start + end) / 2;
            return new TreeNode{
                nodes[i]->val,
                dfs(dfs, start, i),
                dfs(dfs, i + 1, end)};
        };
        return dfs(dfs, 0, nodes.size());
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
