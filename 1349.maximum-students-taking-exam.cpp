/*
 * @lc app=leetcode.cn id=1349 lang=cpp
 * @lcpr version=30112
 *
 * [1349] 参加考试的最大学生数
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstdint>
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
// @lc code=end

// class Solution {
// public:
//     int maxStudents(vector<vector<char>> &seats) {
//         uint64_t map = 0x0;
//         array size = {seats.size(), seats[0].size(), seats.size() * seats[0].size()};
//         for (int i = 0; i < seats.size(); i++)
//             for (int j = 0; j < seats[0].size(); j++)
//                 if (seats[i][j] == '.')
//                     map += 1 << (i * seats[0].size() + j);
//         function<int(unsigned long long, int)> dfs =
//             [&seats, &size, &dfs](unsigned long long map, int ptr) -> int {
//             bool isEnded = true;
//             for (int i = 0; i < size[2]; i++) {
//                 if ((map>>((i+ptr)%size[2]))&0b1) {
//                     ptr += i;
//                     isEnded = false;
//                     break;
//                 }
//             }
//             if (isEnded) return 0;
//             int count_1 = dfs(map+(1<<ptr),ptr);
//             int count_2 = 1 + dfs(
//                 map + (0b111 << (ptr-1)) + (0b101 << (ptr-size[1]-1)) + (0b101 << (ptr+size[1]-1)),
//                 ptr
//             );
//             return max(count_1,count_2);
//         };
//         return dfs(map,0);
//     }
// };

/*
    我超，stack-overflow，暴力出问题了
    这次不得不照抄官方答案了
*/

int main(void) {
    vector<vector<char>> Data = {
        {'.','#'},
        {'#','#'},
        {'#',','},
        {'#','#'},
        {'.','#'}
    };
    ::std::cout << Solution().maxStudents(Data);
}
/*
// @lcpr case=start
// [["#",".","#","#",".","#"],[".","#","#","#","#","."],["#",".","#","#",".","#"]]\n
// @lcpr case=end

// @lcpr case=start
// [[".","#"],["#","#"],["#","."],["#","#"],[".","#"]]\n
// @lcpr case=end

// @lcpr case=start
// [["#",".",".",".","#"],[".","#",".","#","."],[".",".","#",".","."],[".","#",".","#","."],["#",".",".",".","#"]]\n
// @lcpr case=end

 */
