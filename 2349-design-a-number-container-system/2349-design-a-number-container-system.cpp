class NumberContainers {
public:
    unordered_map<int, int> mp;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp1;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        mp[index] = number;
        mp1[number].push(index);
    }
    
    int find(int number) {
        while(!mp1[number].empty()){
            if(mp[mp1[number].top()] == number)
                return mp1[number].top();
            mp1[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */