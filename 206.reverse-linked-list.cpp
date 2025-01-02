/*
 * @lc app=leetcode.cn id=206 lang=cpp
 * @lcpr version=30204
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (75.28%)
 * Likes:    3754
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 *
 *
 * 示例 3：
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 <= Node.val <= 5000
 *
 *
 *
 *
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 *
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
// @lcpr-template-end
class Solution {
public:
    // DFS
    ListNode *reverseList(ListNode *head) {
        ListNode *ans = nullptr;
        auto dfs =
            [&](auto &dfs, const ListNode *prv, ListNode *&cur) {
                if (cur == nullptr) {
                    ans = const_cast<ListNode *>(prv);
                    return;
                }
                dfs(dfs, cur, cur->next);
                cur->next = const_cast<ListNode *>(prv);
            };
        dfs(dfs, nullptr, head);
        return ans;
    }

    // // 直接存储指针
    // ListNode *reverseList(ListNode *head) {
    //     if (head==nullptr)
    //         return nullptr;
    //     vector<ListNode *> nodes;
    //     for (auto p = head; p != nullptr; p = p->next)
    //         nodes.push_back(p);
    //     int n = nodes.size();
    //     for (int i = n - 1; i > 0; i--)
    //         nodes[i]->next = nodes[i - 1];
    //     nodes.front()->next = nullptr;
    //     return nodes.back();
    // }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
