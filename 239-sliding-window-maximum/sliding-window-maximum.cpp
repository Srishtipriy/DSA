class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq;
       vector<int> res;

       for(int i=0; i<nums.size() ; i++){
            //win greater than k nhi hona chaiye ----> 1 <= 5-3  true---> pop 1 so win 2-5
            while( !dq.empty() && dq.front() <= i-k )
                dq.pop_front();
            
            //win m curr val Q.back() se bada ho --true--> pop_back
            while( !dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);   //push indexes

            if(i >= k-1){
                res.push_back( nums[ dq.front() ] );    //jb win banane lage res m push kro
            }
        }
       return res;
    }
};