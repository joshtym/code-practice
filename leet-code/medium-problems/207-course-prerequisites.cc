/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

 

Constraints:

    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.

*/

#include <iostream>
#include <vector>
#include <queue>

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequesites) {
  struct Course {
    int numPrereqs = 0;
    std::vector<int> outgoing;
  };

  std::vector<Course> courses(numCourses, Course());
  std::queue<Course> order;
  std::queue<Course> processNext;

  for (int i = 0; i < prerequesites.size(); ++i) {
    courses[prerequesites[i][1]].numPrereqs++;
    courses[prerequesites[i][0]].outgoing.push_back(prerequesites[i][1]);
  }

  for (int i = 0; i < numCourses; ++i)
    if (courses[i].numPrereqs == 0)
      processNext.push(courses[i]);

  while (!processNext.empty()) {
    Course next = processNext.front();
    processNext.pop();
    order.push(next);

    for (int courseNum : next.outgoing) {
      courses[courseNum].numPrereqs--;

      if (courses[courseNum].numPrereqs == 0)
        processNext.push(courses[courseNum]);
    }
  }

  return order.size() == numCourses;
}

int main(int argc, char** argv) {
  return 0;
}