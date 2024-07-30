/*
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

 

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.

 

Constraints:

    1 <= s.length <= 10^5
    s[i] is 'a' or 'b'​​.

*/

#include <string>
#include <iostream>
#include <vector>

int minimumDeletions(std::string s) {
  int numAs = 0;
  int numBs = 0;
  int minDistance;

  for (int i = 0; i < s.length(); ++i) {
    char c = s[i];
    numAs += c == 'a';
    numBs += c == 'b';
  }

  // String is already balanced
  if (numAs == 0 || numBs == 0)
    return 0;
  
  // Initialize our min distance to be delete all as or delete all bs
  minDistance = std::min(numAs, numBs);
  int totalOperations = 0;

  // Go forwards iteratively and decide to keep or delete bs
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'a') {
      numAs--;

      if (numAs == 0)
        break;
      
      continue;
    }
    
    // Hit b, keep it and delete all the as after (this would be the min operation to balance). We add totalOperations because this
    // is how many bs we've deleted up to this point
    minDistance = std::min(minDistance, numAs + totalOperations);
    totalOperations++;
  }

  totalOperations = 0;

  // Go backwards iteratively and decide to keep or delete as
  for (int i = s.length() - 1; i >= 0; --i) {
    if (s[i] == 'b') {
      numBs--;

      if (numBs == 0)
        break;
      
      continue;
    }
    
    // Hit b, keep it and delete all the as after (this would be the min operation to balance). We add totalOperations because this
    // is how many bs we've deleted up to this point
    minDistance = std::min(minDistance, numBs + totalOperations);
    totalOperations++;
  }

  return minDistance;
}

int main(int argc, char** argv) {
  std::string input;

  while(true) {
    std::cout << "Input?: ";
    std::cin >> input;
    std::cout << minimumDeletions(input) << std::endl;
  }

  return 0;
}