/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30112
 *
 * [23] 合并 K 个升序链表
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
#include <map>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto p = lists.begin(); p!=lists.end();)
            if (*p == nullptr)
                lists.erase(p);
            else 
                p++;
        if (lists.size()==0)
            return nullptr;
        else if (lists.size()==1)
            return lists[0];
        map<int,vector<ListNode*>> data;
        for (auto &list: lists)
            for (auto ptr = list; ptr!=nullptr; ptr=ptr->next)
                data[ptr->val].push_back(ptr);
        ListNode *Ed, *St;
        St = Ed = data.begin()->second[0];
        data.begin()->second.erase(data.begin()->second.begin());
        for (auto &pr: data)
            for (auto &next: pr.second)
                Ed = Ed->next = next;
        return St;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

