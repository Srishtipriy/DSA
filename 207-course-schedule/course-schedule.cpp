class Solution {
public:
    bool canFinish(int vertices, vector<vector<int>>& EdgesSet) {

        // adjacency list
        unordered_map<int, list<int>> adj;
        for (auto &it : EdgesSet) {
            int course = it[0];
            int one_edge = it[1];
            adj[one_edge].push_back(course);
        }

        // indegree array
        vector<int> indegree(vertices, 0);

        // fill indegrees
        for (auto &p : EdgesSet) {
            int course = p[0];
            indegree[course]++;  
        }

        // queue for all nodes with indegree = 0
        queue<int> q;
        for (int i = 0; i < vertices; i++) {
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

        return count == vertices;
    }
};
/*
prerequisites\ edgeset = {
    {1, 0},
    {2, 1},
    {3, 2}
}
1st iteration:
it = {1, 0}             and {1,0} means 0->1 not 1->0
it[0] = 1
it[1] = 0
*/