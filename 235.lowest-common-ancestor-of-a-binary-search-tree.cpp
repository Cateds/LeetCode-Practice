/*
 * @lc app=leetcode.cn id=235 lang=cpp
 * @lcpr version=30117
 *
 * [235] 二叉搜索树的最近公共祖先
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* Ans = nullptr;
        function<bool(TreeNode*&)> dfs = 
        [&Ans,&dfs,&p,&q](TreeNode* &root) -> bool {
            if (root == nullptr)
                return false;
            int Val = root == p or root == q;
            Val += dfs(root->left);
            Val += dfs(root->right);
            if (Val==2)
                Ans = root;
            return Val!=0;
        };
        dfs(root);
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

 */

