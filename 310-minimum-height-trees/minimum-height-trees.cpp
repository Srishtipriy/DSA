class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1)
            return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(degree[i] == 1)
                q.push(i);                      //0 1 2 5  size->4
        }

        int remaining_nodes = n;                //6
        while(remaining_nodes > 2) 
        {
            int node_count = q.size();          //4
            remaining_nodes = remaining_nodes - node_count;     // 6 - 4 = 2 
            for(int i=0; i<node_count; i++) {
                int node = q.front();
                q.pop();

                for(int neighbor : adj[node]) 
                {
                    degree[neighbor ]--;                //jab 3 and 4 ki degree 1 ho jaye q mai push kr do
                    if(degree[neighbor ] == 1)
                        q.push(neighbor );
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};