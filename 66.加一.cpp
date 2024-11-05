/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool needCarry = false;
        digits[digits.size()-1] ++;
        for (int i=digits.size()-1; i>=0; i--) {
            digits[i] += needCarry;
            if (digits[i]>9) {
                needCarry = true;
                digits[i] -= 10;
            }
            else needCarry = false;
        }
        if (needCarry)
            digits.insert(digits.begin(),1);
        return digits;
    }
};
// @lc code=end

int main(void) {
    vector<int> a = {0};
    Solution solute;
    std::cout << solute.plusOne(a)[0];
}

