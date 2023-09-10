/*22. Generate Parentheses
Medium
19.5K
789
Companies
Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(result, "", 0, 0, n);
    return result;
  }

private:
  void backtrack(vector<string> &result, string current, int open, int close,
                 int max) {
    if (current.size() == 2 * max) {
      result.push_back(current);
      return;
    }

    if (open < max) {
      backtrack(result, current + '(', open + 1, close, max);
    }

    if (close < open) {
      backtrack(result, current + ')', open, close + 1, max);
    }
  }
};

int main() {
  Solution solution;

  int n1 = 3;
  int n2 = 1;

  vector<string> result1 = solution.generateParenthesis(n1);
  vector<string> result2 = solution.generateParenthesis(n2);

  cout << "Combinations for n = " << n1 << ":" << endl;
  for (const string &combination : result1) {
    cout << combination << endl;
  }

  cout << "Combinations for n = " << n2 << ":" << endl;
  for (const string &combination : result2) {
    cout << combination << endl;
  }

  return 0;
}
/*Here's how this code works:

The generateParenthesis function takes an integer n as input and returns a
vector of strings representing all combinations of well-formed parentheses.

We initialize an empty vector result to store the generated combinations.

We call the backtrack function with an empty string "", and initial counts of
open and close parentheses set to 0.

The backtrack function recursively generates valid combinations:

If the current string's length reaches 2 * n, we add it to the result vector.
If there are still remaining openings (open < max), we add an open parenthesis.
If it's valid to add a closing parenthesis (close < open), we add one.
The backtrack function is a recursive function that explores all possible
combinations.

You can call the generateParenthesis function with an integer n to generate all
valid combinations of well-formed parentheses. For example:*/