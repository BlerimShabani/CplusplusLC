/*
1. Two Sum
Easy
51.3K
1.7K
Companies
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time
complexity?
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> numToIndex;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
      int complement = target - nums[i];

      if (numToIndex.find(complement) != numToIndex.end()) {
        result.push_back(numToIndex[complement]);
        result.push_back(i);
        break;
      }

      numToIndex[nums[i]] = i;
    }

    return result;
  }
};

int main() {
  Solution solution;
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> result = solution.twoSum(nums, target);

  // Print the result
  if (!result.empty()) {
    std::cout << "Output: [" << result[0] << ", " << result[1] << "]"
              << std::endl;
  } else {
    std::cout << "No valid answer found." << std::endl;
  }

  return 0;
}

/*Explanation:

We define a class Solution with a public function twoSum that takes a vector of
integers nums and an integer target as input. Inside twoSum, we use an unordered
map numToIndex to store the elements and their corresponding indices. We iterate
through nums, and for each element, we calculate its complement (target -
nums[i]). If the complement is already in numToIndex, it means we've found a
pair that sums to the target, so we return the indices. Otherwise, we add the
current element and its index to numToIndex. The function returns a vector
containing the indices.*/