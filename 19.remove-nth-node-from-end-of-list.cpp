/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30112
 *
 * [19] 删除链表的倒数第 N 个结点
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
// @lc code=start
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> Nodes;
        auto ptr = head;
        for (int i=0; i<n; i++) {
            Nodes.push(ptr);
            ptr = ptr->next;
        }
        if (ptr==nullptr) {
            ptr = head->next;
            delete head;
            return ptr;
        }
        else {
            Nodes.push(ptr);
            ptr = ptr->next;
        }
        for (; ptr!=nullptr; ptr=ptr->next) {
            Nodes.push(ptr);
            Nodes.pop();
        }
        auto Prev = Nodes.front();
        Nodes.pop();
        ptr = Nodes.front();
        Prev->next = ptr->next;
        delete ptr;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

