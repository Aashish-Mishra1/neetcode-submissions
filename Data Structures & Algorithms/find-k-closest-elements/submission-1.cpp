class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        int n = arr.size();
        int right = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int left = right-1;
        int count = 0;
        while(left>=0 && right<n && count<k){
            if(abs(x-arr[left])<=abs(x-arr[right])){
                ans.push_back(arr[left]);
                left--;
                count++;
            }
            else{
                ans.push_back(arr[right]);
                right++;
                count++;
            }
        }
        while(count<k && left>=0){
            ans.push_back(arr[left]);
            left--;
            count++;
        }
        while(right<n && count<k){
            ans.push_back(arr[right]);
            right++;
            count++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};