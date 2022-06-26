class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        int n = tasks.size();
        for(int i=0;i<n;i++) tasks[i].push_back(i);     //we are pushing the original index of jobs
        sort(tasks.begin(),tasks.end());
        priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> q;
        //first we need to push all jobs with minimum and same time
        int i = 0;
        long long time = tasks[0][0];
        while(i<n && tasks[i][0]==tasks[0][0]){
            q.push({tasks[i][1],tasks[i][2]});
            i++;
        }
        while(!q.empty()){
            auto job = q.top();
            q.pop();
            ans.push_back(job.second);
            time += job.first; 
            while(i<n && tasks[i][0]<=time){
                q.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            //if arrival time not not matching with total time then q will empty but answer is not calculated
            if(q.empty()){
                int curr = i;
                if(curr<n)  time += tasks[i][0];
                while(curr<n && tasks[curr][0]==tasks[i][0]){
                    q.push({tasks[curr][1],tasks[curr][2]});
                    curr++;
                }
                i = curr;
            }
        }
        return ans;
    }
};