/*
 * @lc app=leetcode.cn id=2736 lang=cpp
 *
 * [2736] 最大和查询
 * 
 * 2023/11/18 每日一题
 * ❓ TODO
 * 超时了😭
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> Res;
        vector<vector<int>> Nums;
        for (int i=0; i<nums1.size(); i++) {
            Nums.push_back(vector<int>(nums1[i],nums2[i]));
        }
        for (int i=0; i<queries.size(); i++)
            queries[i].push_back(i);
        for (auto &i: queries) {
            int count = -1;
            for (int j=0; j<nums1.size(); j++) {
                if (count < nums1[j]+nums2[j] && nums1[j]>=i[0] && nums2[j]>=i[1]) {
                    count = nums1[j]+nums2[j];
                }
            }
            Res.push_back(count);
        }
        return Res;
    }
};
// @lc code=end

