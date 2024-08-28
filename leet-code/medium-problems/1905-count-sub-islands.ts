/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

 

Example 1:

Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Example 2:

Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

 

Constraints:

    m == grid1.length == grid2.length
    n == grid1[i].length == grid2[i].length
    1 <= m, n <= 500
    grid1[i][j] and grid2[i][j] are either 0 or 1.

*/
type Coord = {
  x: number;
  y: number;
};

const countSubIslands = (grid1: number[][], grid2: number[][]): number => {
  let subIslands: number = 0;

  for (let i = 0; i < grid2.length; ++i) {
    for (let j = 0; j < grid2[i].length; ++j) {
      if (!grid2[i][j]) {
        continue;
      }

      const queue: number[][] = [[i, j]];
      const islandCoords: number[][] = [];

      while (queue.length) {
        const [frontX, frontY] = queue[0];
        queue.splice(0, 1);
        grid2[frontX][frontY] = 0;
        islandCoords.push([frontX, frontY]);

        if (frontX > 0 && grid2[frontX - 1][frontY]) {
          queue.push([frontX - 1, frontY]);
        }

        if (frontX < grid2.length - 1 && grid2[frontX + 1][frontY]) {
          queue.push([frontX + 1, frontY]);
        }

        if (frontY > 0 && grid2[frontX][frontY - 1]) {
          queue.push([frontX, frontY - 1]);
        }

        if (frontY < grid2[frontX].length - 1 && grid2[frontX][frontY + 1]) {
          queue.push([frontX, frontY + 1]);
        }
      }

      subIslands += islandCoords.every(([x, y]) => !!grid1[x][y]) ? 1 : 0;
    }
  }
  return subIslands;
};

const countSubIslandsUnion = (grid1: number[][], grid2: number[][]): number => {
  const islandRoot: number[] = new Array(grid2.length * grid2[0].length);
  const islandStatus: number[] = new Array(grid2.length * grid2[0].length).fill(
    0
  );
  let subIslands = 0;

  const findIslandRoot = (x: number) => {
    if (islandRoot[x] !== x) {
      islandRoot[x] = findIslandRoot(islandRoot[x]);
    }

    return islandRoot[x];
  };

  const unionIslands = (x: number, y: number) => {
    const rootX = findIslandRoot(x);
    const rootY = findIslandRoot(y);

    if (rootX !== rootY) {
      islandRoot[rootY] = rootX;
    }
  };

  for (let i = 0; i < grid2.length * grid2[0].length; ++i) {
    islandRoot[i] = i;
  }

  for (let i = 0; i < grid2.length; ++i) {
    for (let j = 0; j < grid2[i].length; ++j) {
      if (grid2[i][j]) {
        if (j < grid2[i].length - 1 && grid2[i][j + 1]) {
          unionIslands(i * grid2[i].length + j, i * grid2[i].length + (j + 1));
        }
        if (i < grid2.length - 1 && grid2[i + 1][j] == 1) {
          unionIslands(i * grid2[i].length + j, (i + 1) * grid2[i].length + j);
        }
      }
    }
  }

  for (let i = 0; i < grid2.length; ++i) {
    for (let j = 0; j < grid2[i].length; ++j) {
      if (grid2[i][j] && !grid1[i][j]) {
        const root = findIslandRoot(i * grid2[i].length + j);
        islandStatus[root] = 2;
      }
    }
  }

  for (let i = 0; i < grid2.length; ++i) {
    for (let j = 0; j < grid2[i].length; ++j) {
      if (grid2[i][j]) {
        const root = findIslandRoot(i * grid2[i].length + j);

        if (islandStatus[root] === 0) {
          subIslands++;
          islandStatus[root] = 1;
        }
      }
    }
  }

  return subIslands;
};

console.log(
  countSubIslands(
    [
      [1, 0, 1, 0, 1],
      [1, 1, 1, 1, 1],
      [0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1],
      [1, 0, 1, 0, 1],
    ],
    [
      [0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1],
      [0, 1, 0, 1, 0],
      [0, 1, 0, 1, 0],
      [1, 0, 0, 0, 1],
    ]
  )
);
