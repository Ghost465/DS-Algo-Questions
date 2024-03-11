/*
Leetcode : https://leetcode.com/problems/course-schedule-ii/description/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> ADJ(numCourses, vector<int>());
        for(int i=0 ; i<prerequisites.size() ; i++) {
            ADJ[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        if(checkCycle(ADJ)){
            return vector<int>();
        }
        vector<int> topoOrder;
        vector<bool> visited(numCourses, false);
        for(int i=0 ; i<numCourses ; i++) {
            constructTopologicalStack(ADJ, i, visited, topoOrder);
        }
        reverse(topoOrder.begin(), topoOrder.end());
        return topoOrder;
    }

    bool checkCycle(vector<vector<int>> &ADJ) {
        for(int i=0 ; i<ADJ.size() ; i++) {
            vector<bool> visited(ADJ.size(), false);
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()) {
                if (!visited[Q.front()]) {
                    visited[Q.front()]=true;
                    for(int j=0 ; j<ADJ[Q.front()].size() ; j++) {
                        if (ADJ[Q.front()][j]==i) {
                            return true;
                        }
                        Q.push(ADJ[Q.front()][j]);
                    }
                }
                Q.pop();
            }
        }
        return false;
    }

    void constructTopologicalStack(vector<vector<int>> &ADJ, int i, vector<bool> &visited, vector<int> &topoOrder){
        if (!visited[i]) {
            visited[i]=true;
            for(int j=0 ; j<ADJ[i].size() ; j++) {
                constructTopologicalStack(ADJ, ADJ[i][j], visited, topoOrder);
            }
            topoOrder.push_back(i);
        }
    }
};
