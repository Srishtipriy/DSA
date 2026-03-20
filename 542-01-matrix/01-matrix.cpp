class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();


        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }


        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            int delX[4] = {-1,0,1,0};
            int delY[4] = {0,1,0,-1};


            for(int i=0;i<4;i++){
                int newX = delX[i] + x;
                int newY = delY[i] + y;
                

                if(newX>=0 && newX<n && newY>=0 && newY<m){
                    if(dp[newX][newY]>1+dp[x][y]){
                        dp[newX][newY]=1+dp[x][y];
                        q.push({newX,newY});
                    }
                }
            }

        }
        return dp;

    }
};