
/*49. Group Anagrams
Medium
17K
492
Companies
Given an array of strings strs, group the anagrams together. You can return the
answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase, typically using all the original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const string &str : strs) {
      string sortedStr = str;
      sort(sortedStr.begin(), sortedStr.end());
      anagramGroups[sortedStr].push_back(str);
    }

    vector<vector<string>> result;
    for (const auto &entry : anagramGroups) {
      result.push_back(entry.second);
    }

    return result;
  }
};

int main() {
  Solution solution;

  vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> result1 = solution.groupAnagrams(strs1);

  vector<string> strs2 = {""};
  vector<vector<string>> result2 = solution.groupAnagrams(strs2);

  vector<string> strs3 = {"a"};
  vector<vector<string>> result3 = solution.groupAnagrams(strs3);

  // Print the results
  for (const auto &group : result1) {
    for (const string &str : group) {
      cout << str << " ";
    }
    cout << endl;
  }

  cout << endl;

  for (const auto &group : result2) {
    for (const string &str : group) {
      cout << str << " ";
    }
    cout << endl;
  }

  cout << endl;

  for (const auto &group : result3) {
    for (const string &str : group) {
      cout << str << " ";
    }
    cout << endl;
  }

  return 0;
}

/*

Here's how this code works:

The groupAnagrams function takes a vector of strings strs.

We use an unordered map anagramGroups where the key is a sorted version of a
string (which will be the same for anagrams), and the value is a vector of
strings that are anagrams of each other.

We iterate through each string in strs. For each string, we create a sorted
version of it, and use it as the key to insert it into the anagramGroups map. We
then push the original string into the corresponding value (vector of anagrams).

After processing all strings, we construct the result vector. We iterate through
the map and push the vectors of anagrams into the result.

Finally, we return the result vector.*/