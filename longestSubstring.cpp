/*3. Longest Substring Without Repeating Characters
Medium
37K
1.7K
Companies
Given a string s, find the length of the longest
substring
 without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a
substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    unordered_set<char> charSet;
    int left = 0, right = 0, maxLength = 0;

    while (right < n) {
      if (charSet.find(s[right]) == charSet.end()) {
        charSet.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
        right++;
      } else {
        charSet.erase(s[left]);
        left++;
      }
    }

    return maxLength;
  }
};

int main() {
  Solution solution;
  string input = "abcabcbb";
  int result = solution.lengthOfLongestSubstring(input);
  cout << "Length of longest substring: " << result << endl;
  return 0;
}

/*Explanation:

We define a class Solution with a public function lengthOfLongestSubstring that
takes a string s as input.

Inside lengthOfLongestSubstring, we initialize n as the length of the input
string s.

We use a sliding window approach with two pointers (left and right) to keep
track of the current substring.

We use an unordered set charSet to keep track of the characters in the current
window.

We iterate over the string s. If the character at right is not in charSet, we
add it, update the maxLength if needed, and move right pointer one step to the
right.

If the character at right is already in charSet, it means we have a repeating
character. In this case, we remove the character at left from charSet and move
left pointer one step to the right.

Finally, we return the maxLength which represents the length of the longest
substring without repeating characters.*/