/*20. Valid Parentheses
Easy
21.9K
1.4K
Companies
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> brackets;

    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        brackets.push(c);
      } else {
        if (brackets.empty()) {
          return false; // Closing bracket with no matching opening bracket
        }
        char top = brackets.top();
        brackets.pop();
        if ((c == ')' && top != '(') || (c == ']' && top != '[') ||
            (c == '}' && top != '{')) {
          return false; // Mismatched opening and closing brackets
        }
      }
    }

    return brackets.empty(); // All opening brackets have been closed
  }
};

int main() {
  Solution solution;

  string s1 = "()";
  string s2 = "()[]{}";
  string s3 = "(]";

  bool result1 = solution.isValid(s1);
  bool result2 = solution.isValid(s2);
  bool result3 = solution.isValid(s3);

  cout << "Is " << s1 << " valid? " << (result1 ? "Yes" : "No") << endl;
  cout << "Is " << s2 << " valid? " << (result2 ? "Yes" : "No") << endl;
  cout << "Is " << s3 << " valid? " << (result3 ? "Yes" : "No") << endl;

  return 0;
}

/*Here's how this code works:

We use a stack (brackets) to keep track of opening brackets.

We iterate through each character in the string.

If we encounter an opening bracket, we push it onto the stack.

If we encounter a closing bracket, we check if there is a corresponding opening
bracket at the top of the stack. If not, or if the brackets don't match, the
string is not valid.

After processing all characters, we check if there are any remaining opening
brackets in the stack. If there are, the string is not valid.

If the stack is empty after processing, the string is valid.

You can call this isValid function with a string containing parentheses to
determine if it's valid or not. For example:*/