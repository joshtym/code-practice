/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

 

Constraints:

    0 <= intervals.length <= 10^4
    intervals[i].length == 2
    0 <= starti <= endi <= 10^5
    intervals is sorted by starti in ascending order.
    newInterval.length == 2
    0 <= start <= end <= 10^5

*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
  std::vector<std::vector<int>> newIntervals;
  bool overlapsFront = false;
  bool overlapsEnd = false;
  bool inserted = false;

  int latestIndexToInput = -1;
  int earliestIndexToEnd = intervals.size();

  for (int i = 0; i < intervals.size(); ++i) {
    if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) {
      latestIndexToInput = i;
      overlapsFront = true;
    } else if (newInterval[0] < intervals[i][0] && (i == 0 || (i >=1 && intervals[i - 1][1] < newInterval[0]))) {
      latestIndexToInput = i;
    }

    if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
      earliestIndexToEnd = i;
      overlapsEnd = true;
    } else if (newInterval[1] < intervals[i][0] && (i == 0 || (i >=1 && intervals[i - 1][1] < newInterval[1]))) {
      earliestIndexToEnd = i;
    }
  }

  // Edge cases for front and end
  if (!overlapsFront && !overlapsEnd && latestIndexToInput == 0 && earliestIndexToEnd == 0) {
    newIntervals = intervals;
    newIntervals.insert(newIntervals.begin(), newInterval);
    return newIntervals;
  }

  if (!overlapsFront && !overlapsEnd && latestIndexToInput == -1 && earliestIndexToEnd == intervals.size()) {
    newIntervals = intervals;
    newIntervals.push_back(newInterval);
    return newIntervals;
  }

  for (int i = 0; i < intervals.size(); ++i) {
    if (latestIndexToInput == i && earliestIndexToEnd == i && !overlapsFront && !overlapsEnd) {
      newIntervals.push_back(newInterval);
      newIntervals.push_back(intervals[i]);
    } else if (latestIndexToInput == i) {
      int start = overlapsFront ? intervals[i][0] : newInterval[0];
      int end = overlapsEnd ? intervals[earliestIndexToEnd][1] : newInterval[1];
      newIntervals.push_back({ start, end });
      i = overlapsEnd ? earliestIndexToEnd : earliestIndexToEnd - 1;
    } else {
      newIntervals.push_back(intervals[i]);
    }
  }

  return newIntervals;
}

int main(int argc, char** argv) {
  // std::vector<std::vector<int>> intervals = {
  //   { 1, 3 },
  //   { 6, 9 }
  // };
  // std::vector<int> interval = { 2, 5 };
  std::vector<std::vector<int>> intervals = {
    { 1, 2 },
    { 3, 5 },
    { 7, 7 },
    { 8, 10 },
    { 12, 16 }
  };
  std::vector<int> interval = { 4, 8 };

  auto result = insert(intervals, interval);

  for (auto interval : result)
    std::cout << interval[0] << ", " << interval[1] << std::endl;

  std::cout << std::endl;

  return 0;
}