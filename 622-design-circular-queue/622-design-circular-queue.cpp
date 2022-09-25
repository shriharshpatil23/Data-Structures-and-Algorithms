class MyCircularQueue {
public:
    deque<int> q;
    int K ;
    MyCircularQueue(int k) {
        K = k;    
      }
    
    bool enQueue(int value) {
        if(q.size()>=K) return false;
        q.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(q.empty())   return false;
        q.pop_front();
        return true;
    }
    
    int Front() {
        if(q.empty())   return -1;
        
        return q.front();
    }
    
    int Rear() {
        if(q.empty())   return -1;
        
        return q.back();
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        if(q.size()>=K) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */