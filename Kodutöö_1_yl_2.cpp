class Solution {
public:
    //selleks et leida maksimaalne v�imalik kasum v�etakse iga p�eva aktsia hind
    int maxProfit(vector<int>& prices) {
        //kontrollib et isegi kui kasumit ei saa siis j��dakse nulli (pole kahjumit)    
        int minPrice = INT_MAX, maxProfit = 0;
        for (int price : prices) {
            minPrice = min(minPrice, price); //otsib milline p�ev oleks kasum v�him
            maxProfit = max(maxProfit, price - minPrice); //arvutab k�ige suurema v�imaliku kasumi
        }
        return maxProfit; //tagastab kasumi v��rtuse
    }
};