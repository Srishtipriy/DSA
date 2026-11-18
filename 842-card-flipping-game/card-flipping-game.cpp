class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        vector<int> bad;
        int n = fronts.size();
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) bad.push_back(fronts[i]);
        }
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (find(bad.begin(), bad.end(), fronts[i]) == bad.end())
                res = min(res, fronts[i]);

            if (find(bad.begin(), bad.end(), backs[i]) == bad.end())
                res = min(res, backs[i]);
        }
        return res == INT_MAX ? 0 : res;
    }
};