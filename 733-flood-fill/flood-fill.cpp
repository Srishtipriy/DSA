class Solution {
public:
    void dfs( vector<vector<int>> &image,int i, int j, int newcolor ,int oldcolor ){
        if( i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] == newcolor || 
            image[i][j] !=oldcolor){
                return;
        }
        image[i][j] = newcolor;

        dfs( image, i-1, j, newcolor, oldcolor );   //top
        dfs( image, i, j+1, newcolor, oldcolor );   //right
        dfs( image, i+1, j, newcolor, oldcolor );   //bottom
        dfs( image, i, j-1, newcolor, oldcolor );   //left
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);

        return image;
    }
};