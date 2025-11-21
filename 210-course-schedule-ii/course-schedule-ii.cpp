class Solution {
public:
    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &recPath,           
        vector<vector<int>>&edges){
            vis[src] = true;
            recPath[src] = true;

            for(int i =0; i<edges.size(); i++){ //  [[1,0],[2,4],[1,3]] type h edges
                int v = edges[i][0];        //reveres order h egde set mai
                int u = edges[i][1];

                if(src == u){
                    if(!vis[v]){
                        if(isCycleDFS(v, vis ,recPath, edges)) 
                            return true;        //agar recr ke andr loop mili
                    }
                    else if(recPath[v]){    //if yes visited && repath is also T
                        return true;        //BACK EDGE->cycle
                    }
                }
            }
            recPath[src] = false;
            return false;
        }
    void Toposort(int src, vector<bool> &vis, stack<int>& s, vector<vector<int>>&edges){
        vis[src] = true;
         
         for(int i =0; i<edges.size(); i++){
                int v = edges[i][0];        //reveres order h egde set mai
                int u = edges[i][1];

                if(src == u){
                    if(!vis[v]){
                        Toposort(v, vis, s, edges);
                    }
                }
        }
         s.push(src);   //by dfs topo order
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        vector<int> ans;

        for(int i =0; i<n; i++){    //sare vertices k liye run kro
            if(!vis[i]){
                if(isCycleDFS( i, vis, recPath, edges )){   //if cycle found
                    return ans;     //return empty vector task tha ans bhi empty h
                }
            }
        }
        //if is loop ke baad bhi koi cycle exist nhi karti
        //topo sort
        stack<int> s;
        //now reinitalise vis vector with false
        vis.assign(n, false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                Toposort(i, vis, s, edges);
            }
        }

        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};