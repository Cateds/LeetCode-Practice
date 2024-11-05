/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 * @lcpr version=30111
 *
 * [1038] 从二叉搜索树到更大和树
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
    int CountValue(TreeNode* Node, const int PrevValue = 0) {
        if (Node->right!=nullptr) {
            int right = CountValue(Node->right,PrevValue);
            Node->val += right;
        }
        else Node->val += PrevValue;
        if (Node->left!=nullptr) {
            int left = CountValue(Node->left,Node->val);
            return left;
        }
        else return Node->val;
    }
    TreeNode* bstToGst(TreeNode* root) {
        CountValue(root);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n
// @lcpr case=end

// @lcpr case=start
// [0,null,1]\n
// @lcpr case=end

 */

