class Solution {
public:
    bool isPossible(int mid,vector<int>&piles,int h){
        
        int hours = 0;
        for(auto pile:piles){
            hours += (pile+mid-1)/mid;
        }

        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        int ans;
        while(low<=high){
            // int mid = (high-low)/2 + low;
            // int mid = (high+low)/2;
            int mid = (high-low)/2 + low;

            if(isPossible(mid,piles,h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return ans;
        
    }
};
