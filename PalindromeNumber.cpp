/*9. Palindrome Number
Easy
11K
2.6K
Companies
Given an integer x, return true if x is a
palindrome
, and false otherwise.



Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome. Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    // Convert the integer to a string
    string str = to_string(x);

    // Initialize pointers for the start and end of the string
    int left = 0;
    int right = str.length() - 1;

    // Compare characters from both ends towards the middle
    while (left < right) {
      if (str[left] != str[right]) {
        return false; // Not a palindrome
      }
      left++;
      right--;
    }

    return true; // It's a palindrome
  }
};

int main() {
  Solution solution;

  // Test cases
  int x1 = 121;
  int x2 = -121;
  int x3 = 10;

  bool result1 = solution.isPalindrome(x1);
  bool result2 = solution.isPalindrome(x2);
  bool result3 = solution.isPalindrome(x3);

  // Output the results
  cout << "Is " << x1 << " a palindrome? " << (result1 ? "Yes" : "No") << endl;
  cout << "Is " << x2 << " a palindrome? " << (result2 ? "Yes" : "No") << endl;
  cout << "Is " << x3 << " a palindrome? " << (result3 ? "Yes" : "No") << endl;

  return 0;
}

/*In this code:

The Solution class with the isPalindrome function is defined as before.

The main function creates an instance of the Solution class.

Three test cases x1, x2, and x3 are defined.

The isPalindrome function is called for each test case and the results are
stored in result1, result2, and result3.

The results are then printed using cout.

return 0; ends the main function and indicates that the program has terminated
successfully.*/