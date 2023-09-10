/*13. Roman to Integer
Easy
12.2K
713
Companies
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and
M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together.
12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four. The same
principle applies to the number nine, which is written as IX. There are six
instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.



Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> romanValues = {{'I', 1},   {'V', 5},   {'X', 10},
                                            {'L', 50},  {'C', 100}, {'D', 500},
                                            {'M', 1000}};

    int result = 0;
    int prevValue = 0;

    // Iterate through the Roman numeral string in reverse order
    for (int i = s.length() - 1; i >= 0; i--) {
      char currentSymbol = s[i];
      int currentValue = romanValues[currentSymbol];

      // Check if we need to subtract the current value
      if (currentValue < prevValue) {
        result -= currentValue;
      } else {
        result += currentValue;
      }

      prevValue = currentValue;
    }

    return result;
  }
};

int main() {
  Solution solution;

  string roman1 = "III";
  string roman2 = "LVIII";
  string roman3 = "MCMXCIV";

  int num1 = solution.romanToInt(roman1);
  int num2 = solution.romanToInt(roman2);
  int num3 = solution.romanToInt(roman3);

  cout << "Integer for " << roman1 << ": " << num1 << endl;
  cout << "Integer for " << roman2 << ": " << num2 << endl;
  cout << "Integer for " << roman3 << ": " << num3 << endl;

  return 0;
}

/*Here's how this code works:

The Solution class defines the romanToInt function, which converts a Roman
numeral string to an integer.

An unordered_map called romanValues is used to map each Roman numeral character
to its corresponding integer value.

We initialize result to 0 to store the final integer value and prevValue to 0 to
keep track of the previous Roman numeral character's value.

We iterate through the Roman numeral string in reverse order (from right to
left).

For each character, we check if it should be added or subtracted based on the
rules of Roman numerals. If the current value is less than the previous value,
we subtract it; otherwise, we add it to the result.

We update prevValue to the current value for the next iteration.

Finally, we return the result, which is the integer equivalent of the Roman
numeral.

In the main function, we test the romanToInt function with three Roman numeral
strings and print the resulting integers.





Regenerate*/