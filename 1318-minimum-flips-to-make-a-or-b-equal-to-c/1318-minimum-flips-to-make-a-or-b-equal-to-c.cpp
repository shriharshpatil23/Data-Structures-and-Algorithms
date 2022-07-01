class Solution {
public:
   void setBit(vector<int> &bit,int a)
    {
        int count = 0;
        while(a)
        {
            if(a & 1)
                bit[count] = 1;
            a = a >> 1;
            count++;
        }
    }
    
    int minFlips(int a, int b, int c) {
        vector<int> bit_a(32,0),bit_b(32,0),bit_c(32,0);
        
       setBit(bit_a,a);
       setBit(bit_b,b);
       setBit(bit_c,c);
        
        
        int count = 0;
       for(int i = 31;i>=0;i--)
       {
           

           if((bit_a[i] | bit_b[i] )== bit_c[i])
               continue;
           else if(bit_c[i] == 1)
               count ++;
           else
               count +=  bit_a[i] + bit_b[i];
          
       }
        return count;
        
    }
};