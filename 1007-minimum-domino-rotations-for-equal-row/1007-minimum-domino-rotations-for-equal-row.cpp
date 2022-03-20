class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        vector<int> face_top(7), face_bottom(7), face_same(7);
        
        for(int i=0; i<n; i++){
            int top = tops[i];
            int bottom = bottoms[i];
            
            ++face_top[top];
            ++face_bottom[bottom];
            
            if(top == bottom) ++face_same[top];
        }
        
        int min_rotation = INT_MAX;
        
        for(int i=1; i<=6; ++i){
            if(face_top[i] + face_bottom[i] - face_same[i] == n){
                
                int min_face = min(face_top[i], face_bottom[i]) - face_same[i];
                
                min_rotation = min(min_rotation,min_face);
            }
        }
        
        return min_rotation == INT_MAX ? -1 : min_rotation;
    }
};