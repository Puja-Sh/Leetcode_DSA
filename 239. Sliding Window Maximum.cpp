// DP SOLUTION --------------------------------------------------------

class Solution {
public:    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n); vector<int> right(n);
        vector<int> output;
        
        // CORNER CASES
        if( n <= 0 || k==0) return output;
        if(k == 1) return nums;
      
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        
        for(int i=1; i<n; i++) {
            if( i %k == 0) {
                left[i] = nums[i];
            }
            else {
                left[i] = max(left[i-1], nums[i]);
            }
            
            int j = n-i-1;              // IMPORTANT
            if( (j+1) % k == 0) {
                right[j] = nums[j];
            }
            else {
                right[j] = max(right[j+1], nums[j]);
            }
        }
        
        for(int i=0; i<n-k+1; i++) {            // IMPORTANT (i < n-k+1)
            int out = max(left[i+k-1], right[i]);
            output.push_back(out);
        }
        return output;
    }
};




// HEAP SOLUTION -----------------------------------------------------

class Solution {
public:    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       priority_queue<pair<int,int>> heap;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++) {
            while(!heap.empty() && heap.top().second <= (i-k)) {
                heap.pop();
            }
                heap.push(make_pair(nums[i], i));
                if(i >= k-1) {
                    ans.push_back(heap.top().first);
                }                       
        }
        return ans;
    }
};





// DEQUE SOLUTION -----------------------------------------------------

class Solution {
public:   
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            // If going out of range pop from front
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();
            
            // If found greater element pop all from the back
            while( !dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }           
            
            // If element is lesser or not going out of range at it
            dq.push_back(i);
            
            // after k operation add front to ans 
            if(i >= k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
