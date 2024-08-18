/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

 

Constraints:

    1 <= s.length <= 10^5
    s consists of only uppercase English letters.
    0 <= k <= s.length
*/

#include <iostream>
#include <string>
#include <vector>

int characterReplacement(std::string s, int k) {
  int numReplacements = 0;

  for (char c = 'A'; c <= 'Z'; ++c) {
    int start = 0;
    int end = 0;
    int replacedCharacters = 0;

    while (end < s.length()) {
      if (s[end] == c)
        end++;
      else if (replacedCharacters < k)
        replacedCharacters++, end++;
      else if (s[start] == c)
        start++;
      else
        start++, replacedCharacters--;
      
      numReplacements = std::max(numReplacements, end - start);
    }
  }

  return numReplacements;
}

int main(int argc, char** argv) {
  std::cout << (int)'A' << " " << (int)'C' << std::endl;
  return 0;
}