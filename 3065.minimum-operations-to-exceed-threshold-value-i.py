#
# @lc app=leetcode.cn id=3065 lang=python3
# @lcpr version=30204
#
# [3065] 超过阈值的最少操作数 I
#
# https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-i/description/
#
# algorithms
# Easy (81.20%)
# Likes:    9
# Dislikes: 0
# Total Accepted:    10.7K
# Total Submissions: 13K
# Testcase Example:  '[2,11,10,1,3]\n10'
#
# 给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。
# 
# 一次操作中，你可以删除 nums 中的最小元素。
# 
# 你需要使数组中的所有元素都大于或等于 k ，请你返回需要的 最少 操作次数。
# 
# 
# 
# 示例 1：
# 
# 输入：nums = [2,11,10,1,3], k = 10
# 输出：3
# 解释：第一次操作后，nums 变为 [2, 11, 10, 3] 。
# 第二次操作后，nums 变为 [11, 10, 3] 。
# 第三次操作后，nums 变为 [11, 10] 。
# 此时，数组中的所有元素都大于等于 10 ，所以我们停止操作。
# 使数组中所有元素都大于等于 10 需要的最少操作次数为 3 。
# 
# 
# 示例 2：
# 
# 输入：nums = [1,1,2,4,9], k = 1
# 输出：0
# 解释：数组中的所有元素都大于等于 1 ，所以不需要对 nums 做任何操作。
# 
# 示例 3：
# 
# 输入：nums = [1,1,2,4,9], k = 9
# 输出：4
# 解释：nums 中只有一个元素大于等于 9 ，所以需要执行 4 次操作。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= nums.length <= 50
# 1 <= nums[i] <= 10^9
# 1 <= k <= 10^9
# 输入保证至少有一个满足 nums[i] >= k 的下标 i 存在。
# 
# 
#


# @lcpr-template-start
from typing import List, Tuple, Dict, Any
from collections import Counter, defaultdict, deque
from heapq import heappush, heappop
from math import ceil, floor, gcd
from itertools import permutations, combinations, product, combinations_with_replacement
from functools import lru_cache
from copy import deepcopy
from bisect import bisect_left, bisect_right
from operator import itemgetter
from random import randint
from string import ascii_lowercase, ascii_uppercase
from datetime import datetime
from time import time
from queue import Queue
from threading import Thread
from concurrent.futures import ThreadPoolExecutor, ProcessPoolExecutor
from multiprocessing import Process, Queue, Manager
import numpy as np
import scipy as sp
# @lcpr-template-end
# @lc code=start
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(
            1 if val < k else 0 
            for val in nums)
        
# @lc code=end



#
# @lcpr case=start
# [2,11,10,1,3]\n10\n
# @lcpr case=end

# @lcpr case=start
# [1,1,2,4,9]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,1,2,4,9]\n9\n
# @lcpr case=end

#

