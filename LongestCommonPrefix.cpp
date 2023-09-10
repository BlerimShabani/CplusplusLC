/*Longest Common Prefix
Easy
15.7K
4.2K
Companies
Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) {
      return "";
    }

    string prefix = strs[0]; // Initialize with the first string

    for (int i = 1; i < strs.size(); i++) {
      int j = 0;

      // Compare characters in the current string with the prefix
      while (j < prefix.size() && j < strs[i].size() &&
             prefix[j] == strs[i][j]) {
        j++;
      }

      // Update the prefix to the common part
      prefix = prefix.substr(0, j);

      // If the prefix becomes empty, there is no common prefix
      if (prefix.empty()) {
        return "";
      }
    }

    return prefix;
  }
};
int main() {
  Solution solution;

  vector<string> strs1 = {"flower", "flow", "flight"};
  vector<string> strs2 = {"dog", "racecar", "car"};

  string commonPrefix1 = solution.longestCommonPrefix(strs1);
  string commonPrefix2 = solution.longestCommonPrefix(strs2);

  cout << "Common Prefix 1: " << commonPrefix1 << endl;
  cout << "Common Prefix 2: " << commonPrefix2 << endl;

  return 0;
}
/*Here's how this code works:

If the input vector strs is empty, we return an empty string since there are no
strings to compare.

We initialize the prefix string with the first string in the vector.

We iterate through the remaining strings in the vector starting from the second
string (index 1).

For each string, we compare characters with the prefix string until we find a
mismatch or reach the end of either string.

We update the prefix to contain only the common part by using the substr
function.

If at any point the prefix becomes empty, we immediately return an empty string
because there is no common prefix.

Finally, we return the prefix, which contains the longest common prefix among
all the strings.

You can call this longestCommonPrefix function with a vector of strings to find
the common prefix. For example:*/