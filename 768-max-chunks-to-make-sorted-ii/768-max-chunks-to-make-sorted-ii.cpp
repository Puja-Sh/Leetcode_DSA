class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        int count = 0;
        
        vector<int> max_from_left(n);
        vector<int> min_from_right(n+1);
        
        min_from_right[n] = INT_MAX;
        
        int res1=-1;
        for(int i=0; i<n; i++){
            int el = arr[i];
            
            res1 = max(res1, el);
            
            max_from_left[i] = res1;
            cout<<max_from_left[i]<<" ";
        }
        cout<<endl;
        
        int res2=INT_MAX;
        for(int i=n-1 ;i>=0; i--){
            int el = arr[i];
            
            res2 = min(res2, el);
            
            min_from_right[i] = res2;
            cout<<min_from_right[i]<<" ";
        }
        
        
        for(int i=0 ;i<n; i++){
            
            int max_left = max_from_left[i];
            int min_right = min_from_right[i+1];
            
            if(min_right >= max_left){
                count++;
            }
            
        }
        
        return count;
    }
};