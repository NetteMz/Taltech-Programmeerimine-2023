class Solution {
public:
    //to get maximum profit it takes prices on every day and then looks when the stock is worth most
    int maxProfit(vector<int>& prices) {
        //enures that even if positive profit can not be made then still user won't lose anything     
        int minPrice = INT_MAX, maxProfit = 0; 
        for (int price : prices) {
            minPrice = min(minPrice, price); //checks the prices to see what could be the most profitable option
            maxProfit = max(maxProfit, price - minPrice);// calculates the maximum profit that could be made
        }
        return maxProfit; //gives the amount of profit
    }
};
