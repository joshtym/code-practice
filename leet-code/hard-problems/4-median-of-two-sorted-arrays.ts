/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

 

Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -10^6 <= nums1[i], nums2[i] <= 10^6

*/
const findMedianSortedArrays = (nums1: number[], nums2: number[]): number => {
  if (
    nums1[nums1.length - 1] <= nums2[0] ||
    nums2[nums2.length - 1] <= nums1[0]
  ) {
    const full =
      nums1[nums1.length - 1] <= nums2[0]
        ? [...nums1, ...nums2]
        : [...nums2, ...nums1];

    if (full.length % 2 == 1) return full[full.length / 2];

    return (full[full.length / 2 - 1] + full[full.length / 2]) / 2;
  }

  const totalElements = nums1.length + nums2.length;
  const needTwoIndices = totalElements % 2 == 0;
  const targetIndex = needTwoIndices
    ? totalElements / 2 - 1
    : totalElements / 2;
  let lowerOne: number = 0;
  let higherOne: number = nums1.length - 1;
  let lowerTwo: number = 0;
  let higherTwo: number = nums2.length - 1;

  // Idea of approach is we need to binary search the elements in each array until we hit the 'target' index
  while (true) {
    let midOne: number = (higherOne + lowerOne) / 2;
    let midTwo: number = (higherTwo + lowerTwo) / 2;
    let currIndex = midOne - lowerOne + (midTwo - lowerTwo);

    // We've found our target index out of the arrays
    if (currIndex == targetIndex) {
      if (needTwoIndices) {
        return -1;
      }
      return nums1[midOne] > nums2[midTwo] ? nums1[midOne] : nums2[midTwo];
    }

    if (totalElements != targetIndex) {
      if (currIndex < targetIndex) {
        if (nums1[midOne] < nums2[midTwo]) {
        }
      } else {
      }
    }
  }

  return 1;
};
