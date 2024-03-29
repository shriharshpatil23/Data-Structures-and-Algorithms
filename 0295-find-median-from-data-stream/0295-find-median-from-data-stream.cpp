class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> minH;
    priority_queue<int> maxH;
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxH.empty() || num<maxH.top()){
            maxH.push(num);
        }else{
            minH.push(num);
        }

        if(maxH.size()>minH.size()+1){
            minH.push(maxH.top());
            maxH.pop();
        }
        else if(minH.size()>maxH.size()+1){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if(maxH.size() == minH.size()){
            return (maxH.top() + minH.top()) / 2.0;
        }else{
            return maxH.size() > minH.size() ? maxH.top() : minH.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */