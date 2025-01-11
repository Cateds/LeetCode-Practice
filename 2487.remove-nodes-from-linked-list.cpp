/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 * @lcpr version=30112
 *
 * [2487] 从链表中移除节点
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
// 用栈的实现方法
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode *> PrevNode;
        PrevNode.push(head);
        auto ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            if (ptr->val <= PrevNode.top()->val) {
                PrevNode.push(ptr);
            }
            else { // ptr->val < PrevNode.top()->val
                do {
                    // delete PrevNode.top();
                    // 这行注释掉由100%原因是为了效率，这个玩意注释掉了效率从5%到了40%
                    // 鉴定为内存安全性换的
                    PrevNode.pop();
                } while (!PrevNode.empty() && PrevNode.top()->val < ptr->val);
                if (!PrevNode.empty()) {
                    PrevNode.top()->next = ptr;
                }
                else {
                    head = ptr;
                }
                PrevNode.push(ptr);
            }
        }
        return head;
    }
};
// @lc code=end

// // 用反转链表的实现方法
// // 鉴定为，效率稀烂，真的
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         if (head == nullptr) return nullptr;
//         ListNode *Ptr_reverse = nullptr;
//         ListNode *Ans = nullptr;
//         for (auto ptr = head; ptr!=nullptr; ptr = ptr->next) {
//             auto toAdd = new ListNode {ptr->val,nullptr};
//             toAdd->next = Ptr_reverse;
//             Ptr_reverse = toAdd;
//         }
//         for (auto ptr = Ptr_reverse; ptr->next!=nullptr;) {
//             if (ptr->next->val < ptr->val) {
//                 auto toDel = ptr->next;
//                 ptr->next = ptr->next->next;
//                 delete toDel;
//             }
//             else {
//                 ptr = ptr->next;
//             }
//         }
//         for (auto ptr=Ptr_reverse; ptr!=nullptr; ptr = ptr->next) {
//             auto toAdd = new ListNode {ptr->val,nullptr};
//             toAdd->next = Ans;
//             Ans = toAdd;
//         }
//         return Ans;
//     }
// };

int main(void) {
    vector data = {5,2,13,3,8};
    ListNode *head , *end;
    head = end = new ListNode {data[0],nullptr};
    for (auto i=1; i<data.size(); i++) {
        end->next = new ListNode {data[i],nullptr};
        end = end->next;
    }
    for (auto ptr = head; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->val << '\n';
    }
    // auto result = Solution().removeNodes(head);
    // for (auto ptr = head; ptr != nullptr; ptr = ptr->next) {
    //     cout << ptr->val << '\n';
    // }
    return 0;
}


/*
// @lcpr case=start
// [5,2,13,3,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

 */

