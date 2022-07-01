class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         // let a and b are distinct numbers
        int a_xor_b = 0;
        for(auto x: nums)
        {
            a_xor_b ^= x;
        }
        // finding first rightmost set bit in a_xor_b
        int mask = 1, first = 0, second = 0;
        while(!(a_xor_b & mask))
            mask <<= 1;
        // finding first number................
        // since xor of a and b has set bit at index i(say) so either a has set bit at ith index or b but not both because their xor bit is set 
        //and other numbers are in pairs so thier xor will be 0.
        for(auto x: nums)
        {
            if(mask & x)
                first ^= x;
        }
        // now to finding second number.....
        // since we know that if a ^ b = c then a ^ c = b and b ^ c = a
        // that is xor operation holds transitive property so
        second = a_xor_b ^ first;
        return {first,second};
    }
};