/*Given a signed 32-bit integer x, return x with its digits reversed. If
reversing x causes the value to go outside the signed 32-bit integer range
[-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or
unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


Constraints:

-231 <= x <= 231 - 1*/

#include <iostream>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    int result = 0;

    while (x != 0) {
      int pop = x % 10;

      // Check for overflow and underflow
      if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) {
        return 0;
      }
      if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) {
        return 0;
      }

      result = result * 10 + pop;
      x /= 10;
    }

    return result;
  }
};

int main() {
  Solution solution;

  // Test cases
  int x1 = 123;
  int x2 = -123;
  int x3 = 120;

  int reversed_x1 = solution.reverse(x1);
  int reversed_x2 = solution.reverse(x2);
  int reversed_x3 = solution.reverse(x3);

  // Output the results
  cout << "Reversed x1: " << reversed_x1 << endl;
  cout << "Reversed x2: " << reversed_x2 << endl;
  cout << "Reversed x3: " << reversed_x3 << endl;

  return 0;
}

/*This defines a class Solution which contains a single function reverse that
takes an integer x as input and returns an integer. The function is responsible
for reversing the digits of x while checking for overflow and underflow.

Inside the reverse function:

int result = 0; initializes a variable result to store the reversed integer.

while (x != 0) starts a loop that continues until x becomes zero. This loop
extracts digits from x and constructs the reversed integer.

int pop = x % 10; calculates the last digit of x and stores it in pop.

The following if statements check for overflow and underflow:

if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) checks if
adding pop to result would cause an overflow.

if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) checks if
adding pop to result would cause an underflow.

If an overflow or underflow is detected, the function immediately returns 0.

result = result * 10 + pop; updates result by appending pop as the next digit.

x /= 10; removes the last digit from x.

return result; returns the reversed integer.*/