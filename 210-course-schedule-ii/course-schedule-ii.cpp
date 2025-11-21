class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& preq) {

        vector<int> degree(num, 0);             // indegree array: how many incoming edges each node has
        vector<vector<int>> adj(num);           // adjacency list: node -> list of nodes reachable from it (outgoing edges)
        vector<int> answer;                     // stores final topological order

        // Build graph using edges
        for(int i = 0; i < preq.size(); i++)
        {
            int u = preq[i][0];                 // destination node
            int v = preq[i][1];                 // source node

            adj[v].push_back(u);                // edge v → u
            degree[u]++;                        // u has one more incoming edge
        }

        queue<int> q;

        // Push all nodes with zero incoming edges
        for(int i = 0; i < num; i++)
        {
            if(degree[i] == 0)
                q.push(i);
        }

        // Kahn's algorithm (BFS topological sort)
        while(!q.empty()){
            int fr = q.front();                 // node with no incoming edges
            answer.push_back(fr);               // add to topological order
            q.pop();

            // Remove outgoing edges from this node
            for(auto it : adj[fr])
            {
                degree[it]--;                   // remove one incoming edge from neighbor
                if(degree[it] == 0)             // if neighbor now has zero incoming edges
                    q.push(it);                 // it is ready to process
            }
        }

        // If any node still has incoming edges → graph has a cycle
        for(int i = 0; i < num; i++)
        {
            if(degree[i] != 0){
                return {};                      // return empty if graph contains a cycle
            }
        }

        return answer;                           // return a valid topological order
    }
};
