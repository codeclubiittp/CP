
**Q1) SORTED ARRAYS MERGE**

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 Output: [1,2,2,3,5,6] Explanation: The arrays we are merging are [1,2,3] and [2,5,6]. The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0 Output: [1] Explanation: The arrays we are merging are [1] and []. The result of the merge is [1].

Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1 Output: [1] Explanation: The arrays we are merging are [] and [1]. The result of the merge is [1]. Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

Input Format:

The first line contains two integers m and n - the number of elements of array num1 and num2.

The second line contains the elements of the array num1.

The third line contains the elements of the array num2.

Constraints:

nums1.length == m + n

nums2.length == n

0 <= m, n <= 200

1 <= m + n <= 200

-109 <= nums1[i], nums2[j] <= 109

Output Format:

Output in a single line the merged sorted array.




**Q2) MINIMUM COINS**

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Input Format:

First line contains n, the length of the integer array.

Second line contains the elements of the integer array.

Third line contains the amount.

Constraints:

1) 1 <= coins.length <= 12
2) 1 <= coins[i] <= 231 - 1
3) 0 <= amount <= 104

Output Format:

Output the fewest number of coins required to get the amount.




**Q3) ISLANDS**

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Input Format:

First line contains two integers m,n - rows and columnns of the matrix, respectively.

Next, m lines begins. Each line contains n elements in it.

Constraints:

m == grid.length

n == grid[i].length

1 <= m, n <= 300

grid[i][j] is '0' or '1'.

Output Format:

Output the number of islands.




**Q4) TRAPPING RAIN WATER**

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1] Output: 6 Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Input Format:

The first line contains one integer n - the size of array

The second line contains the elements of the array.

Constraints:

n == height.length

1 <= n <= 2 * 104

0 <= height[i] <= 105

Output Format:

Output in one line - the water it can trap after raining.
