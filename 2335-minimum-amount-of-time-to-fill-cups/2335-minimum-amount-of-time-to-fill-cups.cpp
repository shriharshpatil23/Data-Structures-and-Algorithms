class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(auto x : amount){
            if(x != 0)      pq.push(x);
        }
        int time = 0;
        while(pq.size()>1){
           int num1=pq.top();
            pq.pop();
            int num2=pq.top();
            pq.pop();
            if(num1!=0 && num2!=0){
                num1--;
                num2--;
                time++;
                if(num1!=0)
                {
                    pq.push(num1);
                }
                if(num2!=0){
                    pq.push(num2);
                }
            }
            else if(num2==0 || num1==0)
            {
                break;
            }
        }
        if(pq.empty()) return time;
        else{
            time += pq.top();
            return time;
        }
    }
};