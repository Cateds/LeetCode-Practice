/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30112
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==nullptr && list2==nullptr) 
            return nullptr;
        else if (list1==nullptr ^ list2==nullptr) 
            return list1==nullptr?list2:list1;
        ListNode *St, *Ed;
        if (list1->val>=list2->val) {
            Ed = St = list2;
            list2 = list2->next;
        }
        else {
            Ed = St = list1;
            list1 = list1->next;
        }
        while (list1!=nullptr && list2!=nullptr) {
            if (list1->val >= list2->val) {
                Ed = Ed->next = list2;
                list2 = list2->next;
            }
            else {
                Ed = Ed->next = list1;
                list1 = list1->next;
            }
        }
        auto Next = list1==nullptr?list2:list1;
        if (Ed!=nullptr) Ed->next = Next;
        return St;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */

