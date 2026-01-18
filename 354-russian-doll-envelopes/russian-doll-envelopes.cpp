class Solution {
private:
static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])        // If the widths are equal, sort in descending order of heights
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];      // Sort in ascending order of widths
    }

int solveBS(int n,vector<vector<int>>& nums)
    {
            //this sorts nums acc to the logic in cmp, instead of the default ascending order
            sort(nums.begin(),nums.end(),cmp);   

            vector<int> ans;
            ans.push_back(nums[0][1]);

            for(int i=1;i<n;i++)
            {
                if(nums[i][1]>ans.back()) 
                    ans.push_back(nums[i][1]);
                else
                {
                    //find index of just bada element in ans
                    int index=lower_bound(ans.begin(),ans.end(),nums[i][1])-ans.begin();//solved in notes
                    ans[index]=nums[i][1];
                }
            }

            return ans.size();
    }       
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        return solveBS(n,envelopes);      
    }
};
