/*12. Integer to Roman
Medium
6.3K
5.3K
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
For example, 2 is written as II in Roman numeral, just two one's added together.
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
Given an integer, convert it to a roman numeral.



Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


Constraints:

1 <= num <= 3999*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string roman = "";
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                        "XL", "X",  "IX", "V",  "IV", "I"};

    for (int i = 0; i < 13; i++) {
      while (num >= values[i]) {
        roman += symbols[i];
        num -= values[i];
      }
    }

    return roman;
  }
};

int main() {
  Solution solution;

  int num1 = 3;
  int num2 = 58;
  int num3 = 1994;

  string roman1 = solution.intToRoman(num1);
  string roman2 = solution.intToRoman(num2);
  string roman3 = solution.intToRoman(num3);

  cout << "Roman numeral for " << num1 << ": " << roman1 << endl;
  cout << "Roman numeral for " << num2 << ": " << roman2 << endl;
  cout << "Roman numeral for " << num3 << ": " << roman3 << endl;

  return 0;
}
/*This code does the following:

Includes necessary header files (<iostream> and <string>).

Defines the Solution class with the intToRoman function, which converts an
integer to a Roman numeral.

Inside the main function:

Creates an instance of the Solution class.
Defines three test cases: num1, num2, and num3.
Calls the intToRoman function for each test case and stores the results in
roman1, roman2, and roman3. Prints the Roman numerals for each test case along
with the original integer.*/