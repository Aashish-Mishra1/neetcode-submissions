class Solution {
public:
    // vector<int> leftComp(vector<int>&ratings){
    //     int n = ratings.size();
    //     vector<int> arr(n,1);

    //     for(int i=1;i<n;i++){
    //         if(ratings[i]>ratings[i-1]){
    //             arr[i] = arr[i-1]+1;
    //         }
    //     }
    //     return arr;
    // }
    vector<int> rightComp(vector<int>&ratings){
        int n = ratings.size();
        vector<int>arr(n,1);

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                arr[i] = arr[i+1]+1;
            }
        }
        return arr;
    }
    int candy(vector<int>& ratings) {
        // vector<int> left = leftComp(ratings);
        vector<int> right = rightComp(ratings);
        int ans = 0;
        int left = 1;
        for(int i=0;i<ratings.size();i++){
            if(i-1>=0 && ratings[i-1]<ratings[i]) left++;
            else left = 1;
            ans += max(left,right[i]);
        }
        return ans;
    }
};