/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

 

Constraints:

    1 <= intervals.length <= 10^4
    intervals[i].length == 2
    0 <= starti <= endi <= 10^4
*/

const merge = (intervals: number[][]): number[][] => {
  const newIntervals: number[][] = [];

  intervals.sort((a, b) => {
    if (a[0] < b[0]) {
      return -1;
    } else if (a[0] > b[0]) {
      return 1;
    } else {
      return 0;
    }
  });

  for (let i = 0; i < intervals.length; ++i) {
    const interval = [...intervals[i]];

    for (let j = i + 1; j < intervals.length; ++j) {
      if (
        (intervals[j][0] >= interval[0] && intervals[j][0] <= interval[1]) ||
        (intervals[j][1] >= interval[0] && intervals[j][1] <= interval[1]) ||
        (intervals[j][0] < interval[0] && intervals[j][1] > interval[1])
      ) {
        interval[0] = Math.min(interval[0], intervals[j][0]);
        interval[1] = Math.max(interval[1], intervals[j][1]);
        intervals.splice(j--, 1);
      }
    }

    newIntervals.push(interval);
  }

  return newIntervals;
};
