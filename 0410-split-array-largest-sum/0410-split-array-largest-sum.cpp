class Solution {
public:
    bool splitsum(vector <int>& nums, int k, int maxsum){
        int subarrays=1;
        int currentsum=0;

        for(int num:nums){
            if(currentsum+num>maxsum){
            subarrays++;
            currentsum=num;
        }else 
        currentsum+=num;
        } return subarrays<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());

        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left<right){
            int mid=left+(right-left)/2;
            if(splitsum(nums, k , mid))
                right=mid;
                else left=mid+1;
            
        }return left;
    }
};