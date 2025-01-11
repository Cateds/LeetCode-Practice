/*
 * @lc app=leetcode.cn id=2008 lang=cpp
 * @lcpr version=30111
 *
 * [2008] 出租车的最大盈利
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
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int,int>>> Rides(n); // 前者是下车地点，后者是总费用
        unordered_map<int,long long> CountMoney_Value;
        for (auto &ride: rides)
            Rides[ride[0]-1].push_back({ride[1]-1,ride[1]-ride[0]+ride[2]});
        function<long long(const int &)> CountMoney = 
        [&n,&Rides,&CountMoney,&CountMoney_Value] (const int &start) -> long long {
            // if (CountMoney_Value.count(start)) return CountMoney_Value[start];
            int ptr = start;
            while (ptr<n && !Rides[ptr].size()) ptr++;
            if (ptr>=n) {
                if (start<n)
                    CountMoney_Value[start] = 0;
                return 0;
            };
            if (CountMoney_Value.count(ptr)) return CountMoney_Value[ptr];
            long long  Ans = CountMoney(ptr+1);
            for (auto &oneRide: Rides[ptr]) {
                long long Ans_2 = oneRide.second + CountMoney(oneRide.first);
                if (Ans_2>Ans) Ans = Ans_2;
            }
            CountMoney_Value[ptr] = Ans;
            return Ans;
        };
        return CountMoney(0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[2,5,4],[1,5,1]]\n
// @lcpr case=end

// @lcpr case=start
// 20\n[[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]\n
// @lcpr case=end

 */

