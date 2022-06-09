class Solution {
public:
    int BinarySearch(vector<int>& numbers, int l, int h, int search){
        
        while(l <= h){
            int mid = (l+h)/2;
            
            if(numbers[mid] == search){
                return mid;
            }else if(numbers[mid] > search){
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return INT_MAX;
        
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        vector<int> ans;
        
        for(int i=0; i<size; i++){
            int search = target - numbers[i];
            int l = i+1;
            int h = size-1;
            
            int searchIndex = BinarySearch(numbers, l, h, search);
            
            if(searchIndex != INT_MAX){
                ans.push_back(i+1);
                ans.push_back(searchIndex+1);
                return ans;
            }
        }
            
        return ans;
    }
};