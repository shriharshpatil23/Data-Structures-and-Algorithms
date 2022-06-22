class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
          int srcX = startPos[0];
        int srcY = startPos[1];
        
        
        int desX = homePos[0];
        int desY = homePos[1];
        
        if(srcX==desX and srcY==desY)
            return 0;
        int total = 0;
        if(desY>srcY)
        {
            while(srcY!=desY)
            {
                srcY++;
                total += colCosts[srcY];
            }
        }
        else
        {
            while(srcY!=desY)
            {
                srcY--;
                total += colCosts[srcY];
            }
        }
        // cout<<total<<" ";
        if(desX>srcX)
        {
            while(srcX!=desX)
            {
                srcX++;
                total += rowCosts[srcX];
            }
        }
        else
        {
            while(srcX!=desX)
            {
                srcX--;
                total += rowCosts[srcX];
            }
        }
        return total;
    }
};