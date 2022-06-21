class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<heights.size()-1;i++){
            int gap = heights[i+1] - heights[i]; 
            if(gap > 0) pq.push(gap);
            
            //ladders are not enough we need to use Bricks
            if(pq.size()>ladders){
                bricks -= pq.top();
                pq.pop();
            }
            //if Gap is greater than the bricks left then we cant move forward;
            if(bricks < 0)  return i;
        }
        //if we reach last element
        return heights.size() - 1;
        }
};