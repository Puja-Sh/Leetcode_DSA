class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long t1=LONG_MIN, t2=LONG_MIN, t3=LONG_MIN;
        
        for(int num:nums){
            if(num == t1 || num == t2 || num == t3){
                continue;
            }
            
            if(num > t1){   // If got max than t1, change t3 = t2 & t2 = t1
                t3 = t2;
                t2 = t1;
                t1 = num;
                
            } else if(num > t2){    // If got max than t2, change t3 = t2
                t3 = t2;
                t2 = num;
                
            } else if(num > t3) {   // If got max than t3, change t3 to current             
                t3 = num;      
            } 
        }
        
        if(t3 == LONG_MIN) return (int)t1;    // If the third largest no present reture maximum (t1)
        
        return (int)t3;
    }
};