/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

Example 2:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:

Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.

 

Constraints:

    2 <= n <= 10^4
    0 <= start, end < n
    start != end
    0 <= a, b < n
    a != b
    0 <= succProb.length == edges.length <= 2*10^4
    0 <= succProb[i] <= 1
    There is at most one edge between every two nodes.

*/
const maxProbabilityFlloyd = (
  n: number,
  edges: number[][],
  succProb: number[],
  start_node: number,
  end_node: number
): number => {
  const maxProb: number[][] = [];

  for (let i = 0; i < n; ++i) {
    const arr: number[] = [];
    for (let j = 0; j < n; ++j) {
      arr.push(0);
    }
    maxProb.push(arr);
  }

  for (let i = 0; i < succProb.length; ++i) {
    const [vertexOne, vertexTwo] = edges[i];
    maxProb[vertexOne][vertexTwo] = succProb[i];
    maxProb[vertexTwo][vertexOne] = succProb[i];
  }

  for (let k = 0; k < n; ++k) {
    for (let i = 0; i < n; ++i) {
      for (let j = 0; j < n; ++j) {
        if (maxProb[i][k] * maxProb[k][j] > maxProb[i][j]) {
          maxProb[i][j] = maxProb[i][k] * maxProb[k][j];
        }
      }
    }
  }

  return maxProb[start_node][end_node];
};

const maxProbabilityBellman = (
  n: number,
  edges: number[][],
  succ: number[],
  start_node: number,
  end_node: number
): number => {
  const dist = new Array(n).fill(0.0);
  dist[start_node] = 1.0;

  for (let i = 0; i < n - 1; ++i) {
    let updated = true;

    for (let j = 0; j < edges.length; ++j) {
      let [u, v] = edges[j];
      let prob = succ[j];

      if (dist[u] * prob > dist[v]) {
        dist[v] = dist[u] * prob;
        updated = true;
      }

      if (dist[v] * prob > dist[u]) {
        dist[u] = dist[v] * prob;
        updated = true;
      }
    }

    if (!updated) {
      break;
    }
  }

  return dist[end_node];
};

console.log(
  maxProbabilityBellman(
    3,
    [
      [0, 1],
      [1, 2],
      [0, 2],
    ],
    [0.5, 0.5, 0.3],
    0,
    2
  )
);
