/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30116
 *
 * [102] 二叉树的层序遍历
 */


// @lcpr-template-start
#include <functional>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> Ans;
        function<void(TreeNode*&,int)> dfs = 
        [&dfs,&Ans](TreeNode* &ptr, int depth) {
            if (ptr==nullptr)
                return;
            if (Ans.size()<=depth)
                Ans.push_back(vector<int>());
            Ans[depth].push_back(ptr->val);
            dfs(ptr->left,depth+1);
            dfs(ptr->right,depth+1);
        };
        dfs(root,0);
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

