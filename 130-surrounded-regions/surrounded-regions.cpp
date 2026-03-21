class Solution {
public:
    int k = 0, used[201][201];
    vector <pair <int, int> > v[201];

    void dfs (int x, int y, int k, vector <vector <char> > &arr) {
        if (x < 0 || x >= arr.size() || y < 0 || y >= arr[x].size() || arr[x][y] == 'X' || used[x][y] == 1) {
            return;
        }
        used[x][y] = 1;
        v[k].push_back(make_pair(x, y));

        dfs (x + 1, y, k, arr);
        dfs (x - 1, y, k, arr);
        dfs (x, y + 1, k, arr);
        dfs (x, y - 1, k, arr);
    }
    void solve(vector<vector<char>>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                if (arr[i][j] == 'O' && used[i][j] == 0) {
                    dfs (i, j, k, arr); k++;
                }
            }
        }
        for (int i = 0; i < k; i++) {
            int ok = 0;

            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j].first == 0 || v[i][j].second == 0 || 
                    v[i][j].first == arr.size() - 1 || v[i][j].second == arr[0].size() - 1) {
                        ok = 1;
                    }
            }

            if (!ok) {
                for (int j = 0; j < v[i].size(); j++) {
                    arr[v[i][j].first][v[i][j].second] = 'X';
                }
            }
        }
    }
};