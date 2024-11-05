/*
 * @lc app=leetcode.cn id=144 lang=cpp
 * @lcpr version=30116
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> Ans;
        function<void(TreeNode*&)> dfs = 
        [&Ans,&dfs](TreeNode* &ptr) {
            if (ptr==nullptr)
                return;
            Ans.push_back(ptr->val);
            dfs(ptr->left);
            dfs(ptr->right);
        };
        dfs(root);
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

