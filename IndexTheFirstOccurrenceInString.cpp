/*28. Find the Index of the First Occurrence in a String
Easy
4.7K
255
Companies
Given two strings needle and haystack, return the index of the first occurrence
of needle in haystack, or -1 if needle is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int n = haystack.length();
    int m = needle.length();

    if (m == 0)
      return 0; // Empty needle matches at position 0.

    for (int i = 0; i <= n - m; i++) {
      if (haystack.substr(i, m) == needle) {
        return i; // Found a match.
      }
    }

    return -1; // No match found.
  }
};

int main() {
  Solution solution;

  string haystack1 = "sadbutsad";
  string needle1 = "sad";

  int result1 = solution.strStr(haystack1, needle1);

  string haystack2 = "leetcode";
  string needle2 = "leeto";

  int result2 = solution.strStr(haystack2, needle2);

  cout << "Result 1: " << result1 << endl; // Output: 0
  cout << "Result 2: " << result2 << endl; // Output: -1

  return 0;
}
/*Here's how this code works:

The strStr function takes two strings, haystack and needle, and returns the
index of the first occurrence of needle in haystack.

We initialize n and m as the lengths of haystack and needle respectively.

If needle is an empty string, it matches at position 0, so we return 0.

We use a loop to iterate through the haystack string. For each position i, we
check if the substring starting from i with the same length as needle is equal
to needle.

If we find a match, we return the index i.

If no match is found in the loop, we return -1 to indicate that needle is not
part of haystack.

You can use this Solution class to find the index of the first occurrence of
needle in haystack. For example:*/