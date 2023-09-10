/*5. Longest Palindromic Substring
Medium
27.1K
1.6K
Companies
Given a string s, return the longest
palindromic

substring
 in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0, maxLen = 1;

    // All substrings of length 1 are palindromic
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        start = i;
        maxLen = 2;
      }
    }

    // Check for substrings of length greater than 2
    for (int k = 3; k <= n; k++) {
      for (int i = 0; i < n - k + 1; i++) {
        int j = i + k - 1;

        // Check if substring s[i+1:j-1] is a palindrome and s[i] is equal to
        // s[j]
        if (dp[i + 1][j - 1] && s[i] == s[j]) {
          dp[i][j] = true;
          if (k > maxLen) {
            start = i;
            maxLen = k;
          }
        }
      }
    }

    return s.substr(start, maxLen);
  }
};

int main() {
  Solution solution;
  string input = "babad";
  string result = solution.longestPalindrome(input);
  cout << "Longest Palindromic Substring: " << result << endl;
  return 0;
}
