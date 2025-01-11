/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 * @lcpr version=30110
 *
 * [1457] 二叉树中的伪回文路径
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void checkTreeNode(TreeNode* Node, int& Res) {
        static array<int,9> Count;
        if (Node==nullptr) return;
        Count[Node->val-1]++;
        if (Node->left==nullptr && Node->right==nullptr) {
            int Odd = 0;
            for (int i=0; i<9; i++)
                if (Count[i]%2==1) Odd++;
            if (Odd<=1) Res++;
        }
        else {
            checkTreeNode(Node->left, Res);
            checkTreeNode(Node->right, Res);
        }
        Count[Node->val-1]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int Res = 0;
        checkTreeNode(root, Res);
        return Res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,3,1,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1,1,3,null,null,null,null,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [9]\n
// @lcpr case=end

 */

