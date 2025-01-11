/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30113
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,pair<ListNode*,ListNode*>> Link;
        for (auto p=head; p!=nullptr; p=p->next) {
            if (Link.find(p->val) == Link.end())
                Link[p->val].first = p;
            if (p->next==nullptr or p->val!=p->next->val)
                Link[p->val].second = p;
        }
        head = nullptr;
        ListNode* PrevPtr = nullptr;
        for (auto &[_,p]: Link) {
            auto &[ptr, ptr_end] = p;
            if (ptr != ptr_end)
                continue;
            else {
                if (head==nullptr)
                    head = ptr;
                if (PrevPtr!=nullptr)
                    PrevPtr->next = ptr;
                PrevPtr = ptr;
            }
        }
        return head;
    }
};
// @lc code=end
int main(void) {
    vector data = {1,1};
    vector<ListNode> Nodes;
    for (int i=0; i<data.size(); i++) {
        Nodes.push_back({i,nullptr});
        if (i>0)
            Nodes[i-1].next = &Nodes[i];
    }
    auto result = Solution().deleteDuplicates(&Nodes[0]);
    for (auto p=result; p!=nullptr; p=p->next)
        printf("%d ",p->val);
}


/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */

