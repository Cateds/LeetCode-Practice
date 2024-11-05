/*
 * @lc app=leetcode.cn id=103 lang=cpp
 * @lcpr version=30116
 *
 * [103] 二叉树的锯齿形层序遍历
 */


// @lcpr-template-start
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
using namespace std;
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> Ans;
        function< void (TreeNode* &, int )> dfs = 
        [&dfs,&Ans](TreeNode* &ptr ,int depth) {
            if (ptr==nullptr)
                return;
            if (Ans.size()==depth)
                Ans.push_back(vector<int>());
            Ans[depth].push_back(ptr->val);
            dfs(ptr->left,depth+1);
            dfs(ptr->right,depth+1);
        };
        dfs(root,0);
        for (int i=1; i<Ans.size(); i+=2) {
            Ans[i] = vector<int>(Ans[i].rbegin(),Ans[i].rend());
        }
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

