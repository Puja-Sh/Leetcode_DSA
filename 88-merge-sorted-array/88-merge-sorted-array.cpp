class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1, p2=nums2.size()-1;
        int i= nums1.size()-1;
        
        while(p2>=0){
             if(p1>= 0 && nums1[p1] > nums2[p2]) {
                nums1[i] = nums1[p1];
                p1--;
            } else {
                nums1[i] = nums2[p2]; 
                p2--;
            }
            i--;
        }
    }
};