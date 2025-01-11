/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 * @lcpr version=30111
 *
 * [2415] 反转二叉树的奇数�?
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*,int>> Tasks;
        Tasks.push({root,0});
        for (
            auto task=Tasks.front();
            !Tasks.empty();
            Tasks.pop(),task=Tasks.front()
        ) {
            
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,5,8,13,21,34]\n
// @lcpr case=end

// @lcpr case=start
// [7,13,11]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]\n
// @lcpr case=end

 */

