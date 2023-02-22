class Solution {
public:
    //selleks et leida maksimaalne vıimalik kasum vıetakse iga p‰eva aktsia hind
    int maxProfit(vector<int>& prices) {
        //kontrollib et isegi kui kasumit ei saa siis j‰‰dakse nulli (pole kahjumit)    
        int minPrice = INT_MAX, maxProfit = 0;
        for (int price : prices) {
            minPrice = min(minPrice, price); //otsib milline p‰ev oleks kasum v‰him
            maxProfit = max(maxProfit, price - minPrice); //arvutab kıige suurema vıimaliku kasumi
        }
        return maxProfit; //tagastab kasumi v‰‰rtuse
    }
};