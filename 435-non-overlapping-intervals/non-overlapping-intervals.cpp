class Solution {
public:
    static bool compare(vector<int>&a , vector<int> &b){
            return a[1]< b[1];
        }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty() ){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), compare);          //sorted using compare

        int count = 0;
        int last_int = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < last_int ){
                count++;
            }
            else{
                last_int= intervals[i][1];
            }
        }
        return count;
    }
};