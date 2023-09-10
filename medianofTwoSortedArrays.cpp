/*4. Median of Two Sorted Arrays
Hard
25.6K
2.8K
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106*/
#include <algorithm>
#include <iostream> // Include necessary libraries
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    // Make sure nums1 is smaller or equal to nums2
    if (nums1.size() > nums2.size()) {
      std::swap(nums1, nums2);
    }

    int m = nums1.size(); // Get sizes of both input vectors
    int n = nums2.size();
    int left = 0, right = m;       // Initialize variables for binary search
    int halfLen = (m + n + 1) / 2; // Calculate the midpoint

    while (left < right) {
      int i = left + (right - left) / 2; // Calculate partition positions
      int j = halfLen - i;

      // Adjust the search range based on comparison
      if (nums1[i] < nums2[j - 1]) {
        left = i + 1;
      } else {
        right = i;
      }
    }

    int i = left; // Final partition positions
    int j = halfLen - left;

    // Calculate maximum values on both sides
    int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
    int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
    int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
    int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

    if ((m + n) % 2 == 0) { // If even total elements
      return (std::max(nums1LeftMax, nums2LeftMax) +
              std::min(nums1RightMin, nums2RightMin)) /
             2.0;
    } else { // If odd total elements
      return std::max(nums1LeftMax, nums2LeftMax);
    }
  }
};

int main() {
  std::vector<int> nums1 = {1, 3}; // Define input vectors
  std::vector<int> nums2 = {2};

  Solution solution; // Create an instance of the Solution class
  double median =
      solution.findMedianSortedArrays(nums1, nums2); // Call the function

  std::cout << "Median: " << median << std::endl; // Print the result

  return 0; // Indicate successful execution
}
