class KthLargest {
private:
    int k;
    vector<int>elements;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        elements = nums;
    }
    
    int add(int val) {
        elements.push_back(val);
        sort(elements.begin(),elements.end());

        int n = elements.size();
        
        return elements[n-k];
        
    }
};
