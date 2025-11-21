class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& grid, int n, int m){
        if(i<0 || j<0 || i>= n|| j>=m || vis[i][j] || grid[i][j] != '1'){
            //vis[i][j] means already visted
            //yaad rakho provided char grid h so->> grid[i][j] mai if!= 1 return kar do
            return ;
        }
        vis[i][j]=true;

        dfs(i-1, j  , vis , grid, n , m);    //top        
        dfs( i , j+1, vis , grid, n , m);    //right
        dfs(i+1, j  , vis , grid, n , m);    //bottom    
        dfs( i , j-1, vis , grid, n , m);    //left    
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m , false));   
        //grid banai and har yek block mai F store kiya hai

        for(int i=0 ; i<n ;i++){
            for(int j=0; j<m; j++){
                //if grid mai 1 hai and not visited marked hai tbh
                if( grid[i][j]=='1' && !vis[i][j]){ 

                    dfs(i , j ,vis , grid, n, m);  //means 1 island visitho gaya
                    islands++;
                }
            }
        }
    return islands;
    }
};