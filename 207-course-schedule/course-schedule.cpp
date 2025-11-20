class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // adjacency list
        unordered_map<int, list<int>> adj;
        for (auto &it : prerequisites) {
            int course = it[0];
            int prereq = it[1];
            adj[prereq].push_back(course);
        }

        // indegree array
        vector<int> indegree(numCourses, 0);

        // fill indegrees
        for (auto &p : prerequisites) {
            int course = p[0];
            indegree[course]++;  
        }

        // queue for all nodes with indegree = 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto neighbour : adj[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return count == numCourses;
    }
};
/*
prerequisites = {
    {1, 0},
    {2, 1},
    {3, 2}
}
1st iteration:
it = {1, 0}             and {1,0} means 0->1 not 1->0
it[0] = 1
it[1] = 0
*/