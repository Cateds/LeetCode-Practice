/*
 * @lc app=leetcode.cn id=590 lang=cpp
 * @lcpr version=30116
 *
 * [590] N 叉树的后序遍历
 */


// @lcpr-template-start
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
// @lcpr-template-end
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start


class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> Ans;
        function<void(Node*&)> dfs =
        [&dfs,&Ans](Node* &ptr) {
            if (ptr==nullptr)
                return;
            for (auto &ch: ptr->children)
                dfs(ch);
            Ans.push_back(ptr->val);
        };
        dfs(root);
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,3,2,4,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
// @lcpr case=end

 */

