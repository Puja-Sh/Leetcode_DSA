class Solution {
public:
    int hammingDistance(int x, int y) {
        vector<int> vx(32);
        vector<int> vy(32);
        
        vx = helperBits(x);
        vy = helperBits(y);
        
        int count = 0;
        for(int i=0; i<32; i++) {
            if(vx[i] != vy[i]){
                count++;
            }
        }
        return count;
    }
    
    vector<int> helperBits(int num){
        vector<int> bits(32, 0);
        
        int i=0;
        while(num > 0){
            bits[i] = num%2;
            num /= 2;
            i++;
        }
        return bits;
    }
};