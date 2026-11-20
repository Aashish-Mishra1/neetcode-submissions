class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return (double)(maxHeap.top()+minHeap.top())/2.0;
        }
        else
        return (double)maxHeap.top();
    }
};
