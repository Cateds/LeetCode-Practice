// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3165 lang=cpp
 * @lcpr version=30204
 *
 * [3165] 不包含相邻元素的子序列的最大和
 *
 * https://leetcode.cn/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/description/
 *
 * algorithms
 * Hard (27.13%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 19K
 * Testcase Example:  '[3,5,9]\n[[1,-2],[0,-3]]'
 *
 * 给你一个整数数组 nums 和一个二维数组 queries，其中 queries[i] = [posi, xi]。
 *
 * 对于每个查询 i，首先将 nums[posi] 设置为 xi，然后计算查询 i 的答案，该答案为 nums 中 不包含相邻元素 的 子序列 的 最大
 * 和。
 *
 * 返回所有查询的答案之和。
 *
 * 由于最终答案可能非常大，返回其对 10^9 + 7 取余 的结果。
 *
 * 子序列 是指从另一个数组中删除一些或不删除元素而不改变剩余元素顺序得到的数组。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,5,9], queries = [[1,-2],[0,-3]]
 *
 * 输出：21
 *
 * 解释：
 * 执行第 1 个查询后，nums = [3,-2,9]，不包含相邻元素的子序列的最大和为 3 + 9 = 12。
 * 执行第 2 个查询后，nums = [-3,-2,9]，不包含相邻元素的子序列的最大和为 9 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,-1], queries = [[0,-5]]
 *
 * 输出：0
 *
 * 解释：
 * 执行第 1 个查询后，nums = [-5,-1]，不包含相邻元素的子序列的最大和为 0（选择空子序列）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -10^5 <= nums[i] <= 10^5
 * 1 <= queries.length <= 5 * 10^4
 * queries[i] == [posi, xi]
 * 0 <= posi <= nums.length - 1
 * -10^5 <= xi <= 10^5
 *
 *
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
// @lc code=start
class SegTree {
private:
    class Node {
    public:
        Node *l, *r;
        array<long, 4> data;
        Node(Node *&&lp, Node *&&rp,
             array<long, 4> &&data_v)
            : l(lp), r(rp), data(data_v) {}
    };

    Node *root;
    unsigned int size;

    Node *BuildTree(vector<int> &sums,
                    const int &begin,
                    const int &end) {
        auto length = end - begin;
        if (length == 1) { // leaves
            return new Node(
                nullptr, nullptr,
                {max(sums[begin], 0), 0, 0, 0});
        } else { // branches
            auto ret = new Node(
                BuildTree(sums, begin, begin + length / 2),
                BuildTree(sums, begin + length / 2, end),
                {0, 0, 0, 0});
            for (int i = 0; i < 4; i++) {
                ret->data[i] =
                    max(ret->l->data[i | 0b01] +
                            ret->r->data[i & 0b01],
                        ret->l->data[i & 0b10] +
                            ret->r->data[i | 0b10]);
            }
            return ret;
        }
    }

    void DestroyTree(Node *&tree) {
        if (tree != nullptr) {
            DestroyTree(tree->l);
            DestroyTree(tree->r);
            delete tree;
        }
        return;
    }

    void ChangeNode(Node *ptr,
                    vector<int> &query,
                    const int &begin,
                    const int &end) {
        auto length = end - begin;
        if (length == 1) { // leaves
            ptr->data = {max(query[1], 0), 0, 0, 0};
        } else { // branches
            if (query[0] < begin + length / 2)
                ChangeNode(ptr->l, query, begin, begin + length / 2);
            else
                ChangeNode(ptr->r, query, begin + length / 2, end);
            for (int i = 0; i < 4; i++)
                ptr->data[i] =
                    max(ptr->l->data[i | 0b01] +
                            ptr->r->data[i & 0b01],
                        ptr->l->data[i & 0b10] +
                            ptr->r->data[i | 0b10]);
            return;
        }
    }

public:
    SegTree(vector<int> &sums) {
        root = BuildTree(sums, 0, sums.size());
        size = sums.size();
    }
    ~SegTree(void) {
        // DestroyTree(root);
    }

    auto getMaxVal(void) {
        return root->data[0];
    }
    void QueryTask(vector<int> &query) {
        ChangeNode(root, query, 0, size);
    }
};
class Solution {
private:
public:
    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries) {
        long long ans = 0;
        SegTree st(nums);
        for (auto &qu : queries) {
            st.QueryTask(qu);
            ans += st.getMaxVal();
        }
        return ans % (1000000007);
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maximumSumSubsequence
// paramTypes= ["number[]","number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [3,5,9]\n[[1,-2],[0,-3]]\n
// @lcpr case=end

// @lcpr case=start
// [0,-1]\n[[0,-5]]\n
// @lcpr case=end

 */
