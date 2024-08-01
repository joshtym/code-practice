/*
You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

    For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

 

Example 1:

Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.

Example 2:

Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
Output: 4

Example 3:

Input: books = [[7,3], [8,7], [2,7], [2,5]], shelfWidth = 10
Expected: 15

Constraints:

    1 <= books.length <= 1000
    1 <= thicknessi <= shelfWidth <= 1000
    1 <= heighti <= 1000


*/

#include <iostream>
#include <vector>

int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
  int size = books.size();
  std::vector<int> maxHeights(size + 1, INT_MAX);

  // Base case for zero books
  maxHeights[0] = 0;

  for (int i = 1; i <= books.size(); ++i) {
    int totalWidth = 0;
    int maxHeight = 0;

    // Iterate over each previous 'max height' and try to place the book with that shelf
    for (int j = i; j > 0; --j) {
      totalWidth += books[j - 1][0];

      if (totalWidth > shelfWidth)
         break;
        
      maxHeight = std::max(maxHeight, books[j - 1][1]);
      maxHeights[i] = std::min(maxHeights[i], maxHeights[j - 1] + maxHeight);
    }
  }

  return maxHeights[size];
}

int main(int argc, char** argv) {
  // std::vector<std::vector<int>> books = {
  //   { 1, 1 },
  //   { 2, 3 },
  //   { 2, 3 },
  //   { 1, 1 },
  //   { 1, 1 },
  //   { 1, 1 },
  //   { 1, 2 }
  // };
  // int shelfWidth = 4;

  // std::vector<std::vector<int>> books = {
  //   { 1, 3 },
  //   { 2, 4 },
  //   { 3, 2 },
  // };
  // int shelfWidth = 6;

  std::vector<std::vector<int>> books = {
    { 7, 3 },
    { 8, 7 },
    { 2, 7 },
    { 2, 5 }
  };
  int shelfWidth = 10;

  std::cout << minHeightShelves(books, shelfWidth) << std::endl;

  return 0;
}