class Solution {
public:
    //selleks et leida maksimaalne võimalik kasum võetakse iga päeva aktsia hind
    int maxProfit(vector<int>& prices) {
        //kontrollib et isegi kui kasumit ei saa siis jäädakse nulli (pole kahjumit)    
        int minPrice = INT_MAX, maxProfit = 0; 
        for (int price : prices) {
            minPrice = min(minPrice, price); //otsib milline päev oleks kasum vähim
            maxProfit = max(maxProfit, price - minPrice); //arvutab kõige suurema võimaliku kasumi
        }
        return maxProfit; //tagastab kasumi väärtuse
    }
};
