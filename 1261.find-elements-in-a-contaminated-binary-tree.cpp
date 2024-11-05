/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 * @lcpr version=30119
 *
 * [1261] 在受污染的二叉树中查找元素
 */


// @lcpr-template-start
using namespace std;
#include <unordered_map>
#include <functional>
#include <vector>
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
#include <unordered_set>
#include <utility>
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
class FindElements {
private:
    unordered_map<int,bool> isExist;
public:
    FindElements(TreeNode* root) {
        auto & exist = isExist;

        function<void(TreeNode*&)> dfs = 
        [&exist,&dfs](TreeNode *& ptr) {
            if (ptr->left != nullptr) {
                ptr->left->val = ptr->val * 2 + 1;
                dfs(ptr->left);
                exist[ptr->left->val] = true;
            }
            if (ptr->right != nullptr) {
                ptr->right->val = ptr->val * 2 + 2;
                dfs(ptr->right);
                exist[ptr->right->val] = true;
            }
        };
        root->val = 0;
        exist[0] = true;
        dfs(root);
    }
    
    bool find(int target) {
        return isExist[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end



/*
// @lcpr case=start
// ["FindElements","find","find"][[[-1,null,-1]],[1],[2]]\n
// @lcpr case=end

// @lcpr case=start
// ["FindElements","find","find","find"][[[-1,-1,-1,-1,-1]],[1],[3],[5]]\n
// @lcpr case=end

// @lcpr case=start
// ["FindElements","find","find","find","find"][[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]\n
// @lcpr case=end

 */

