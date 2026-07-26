class Solution {
public:
       bool caneat(vector <int>&piles, int h, int speed){
        long long hours=0;
        for(int pile:piles){
            hours+=(pile+speed-1)/speed;
            if(hours>h){
                return false;
            }
        }
        return true;
       }



    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right = *max_element(piles.begin(), piles.end());
        while (left < right) {

            int mid = left + (right - left) / 2;

            if (caneat(piles, h, mid))
                right = mid;
            else
                left = mid + 1;}
                return left;
        
    }
};