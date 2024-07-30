
/*
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

    Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
    A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:

Input: rating = [1,2,3,4]
Output: 4

 

Constraints:

    n == rating.length
    3 <= n <= 1000
    1 <= rating[i] <= 10^5
    All the integers in rating are unique.


*/

#include <iostream>
#include <vector>

// Brute force soln
int numTeams(std::vector<int>& rating) {
  std::vector<bool> hashMap(100001, false);
  std::vector<int> noDupes;
  int teamNum = 0;

  for (int num : rating)
    if (!hashMap[num]) {
      hashMap[num] = true;
      noDupes.push_back(num);
    }
  
  for (int i = 0; i < noDupes.size() - 2; ++i) {
    for (int j = i + 1; j < noDupes.size() - 1; ++j) {
      for (int k = j + 1; k < noDupes.size(); ++k) {
        if ((noDupes[i] < noDupes[j] && noDupes[j] < noDupes[k]) || (noDupes[i] > noDupes[j] && noDupes[j] > noDupes[k])) {
          ++teamNum;
        }
      }
    }
  }

  return teamNum;
}

int numTeamsSmarter(std::vector<int>& rating) {
  std::vector<bool> hashMap(100001, false);
  int teamNum = 0;
  int noDupeIndex = -1;
  std::vector<int> noDupes;

  for (int num : rating)
    if (!hashMap[num]) {
      hashMap[num] = true;
      noDupes.push_back(num);
    }

  for (int i = 1; i < noDupes.size() - 1; ++i) {
    int mid = rating[i];
    int earlyLess = 0;
    int earlyGreat = 0;
    int afterLess = 0;
    int afterGreat = 0;

    for (int j = 0; j < noDupes.size(); ++j) {
      if (j < i) {
        if (rating[j] < mid)
          earlyLess++;
        else if (rating[j] > mid)
          earlyGreat++;
      } else if (j > i) {
        if (rating[j] < mid)
          afterLess++;
        else if (rating[j] > mid)
          afterGreat++;
      }
    }

    teamNum += (earlyLess * afterGreat);
    teamNum += (earlyGreat * afterLess);
  }
  
  return teamNum;
}

int main(int argc, char** argv) {
  std::vector<int> ratings;

  for (int i = 1; i < argc; ++i)
    ratings.push_back(std::stoi(argv[i]));

  std::cout << numTeamsSmarter(ratings) << std::endl;

  return 0;
}