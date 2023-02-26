//Värvide sorteerimine

class Solution{
public:
    void sortColors(vector<int>& n){
        int 
        a=0, //nr 0 positsioon
        b=0, //järjekorra nr
        c=n.size()-1;//nr 2 positsioon
        
        while(b<=c){ //seni kuni järjekorra nr on väiksem või võrdne
            if(n[b]==0){ //kui järjekorra nr asub number 0
                n[b]=n[a]; //vahetatakse ümber järjekorra numbril olev arv ja nr 0 positsioonil olev arv
                n[a]=0; //nr 0 positsioonil on arv 0
                a++; //nr 0 positsioon liigub ühe võrra edasi
                b++; //järjekorra nr liigub ühe võrra edasi
            }else if (n[b]==2){ //kui järjekorra numbril asub arv 2
                n[b]=n[c];
                n[c]=2;
                c--;
            }else
                b++; // kui järjekorra numbril asuv arv on 1 siis järjekorra number liiguba ühe võrra edasi
        }
    }
};
