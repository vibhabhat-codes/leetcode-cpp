class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int maxprice=0;
        for (int price : prices){
            maxprice=max(maxprice,price-minprice);
            minprice=min(minprice,price);
        }
        return maxprice;
    }
};