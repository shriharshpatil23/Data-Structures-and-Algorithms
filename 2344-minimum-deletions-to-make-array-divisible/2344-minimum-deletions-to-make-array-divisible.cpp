class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int x=b[0];
        for(int i=0;i<b.size();i++){
		// take gcd of second array
            x=__gcd(x,b[i]);
        }
        priority_queue<int,vector<int> , greater<int> > p;
        for(int i=0;i<a.size();i++){
		// insert all elements of first array into priority queue
            p.push(a[i]);
        }
        int cnt=0;
        while(!p.empty()){
            int y=p.top();
            cnt++;
            if(x%y==0){
			// if the gcd of second array is divisible by top element of min-priority queue then return current count
                return cnt-1;
            }
            p.pop();
        }
		// if no answer is present then return -1
        return -1;
    }
};