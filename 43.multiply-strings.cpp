/*
 * @lc app=leetcode.cn id=43 lang=cpp
 * @lcpr version=30112
 *
 * [43] 字符串相乘
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
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0")
            return "0";
        auto multi =
        [](const string &num1, const char &num2) {
            int plus = 0;
            stack<int> rAns;
            string Ans;
            for (auto n = num1.rbegin(); n!=num1.rend(); n++) {
                int num = (num2-'0') * (*n-'0') + plus;
                rAns.push(num%10);
                plus = num/10;
            }
            if (plus) {
                rAns.push(plus);
            }
            while (!rAns.empty()) {
                Ans += rAns.top() + '0';
                rAns.pop();
            }
            return Ans;
        };
        auto plus =
        [](const string &num1, const string &num2) {
            bool plus = false;
            stack<int> rAns;
            string Ans;
            // pair size = {min(num1.length(),num2.length()),max(num1.length(),num2.length())};
            auto &num_lower = num1.length() > num2.length() ? num2 : num1 ;
            auto &num_larger = num1.length() > num2.length() ? num1 : num2 ;
            for (int i=0; i<num_lower.length(); i++) {
                int num = num_larger.end()[-1-i] + num_lower.end()[-1-i] + plus - 2*'0';
                plus = num/10;
                rAns.push(num%10);
            }
            for (int i=num_lower.length(); i<num_larger.length(); i++) {
                int num = num_larger.end()[-1-i] + plus - '0';
                plus = num/10;
                rAns.push(num%10);
            }
            if (plus)
                rAns.push(plus);
            while (!rAns.empty()) {
                Ans += rAns.top() + '0';
                rAns.pop();
            }
            return Ans;
        };
        string Ans;
        for (int i=0; i<num1.size(); i++) {
            auto result = multi(num2,num1.end()[-1-i]);
            for (int j=0; j<i; j++)
                result.push_back('0');
            Ans = plus(Ans,result);
        }
        return Ans;
    }
};
// @lc code=end

int main(void) {
    cout << Solution().multiply("123","2");
    cout << "\nFinish\n";
}
/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */

