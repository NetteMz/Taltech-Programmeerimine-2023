//Õnnelik number

class Solution{
public:
    bool isHappy(int n) { // bool on tingimuslik väärtus õige või vale
        if(n==1) // kontrollib, et väärtus oleks 1
        return true; // väljastab, et väärtus on õige

        if(n<3) // kontrollib, et väärtus oleks väiksem 3
        if(n!=1) 
        return false; // väljastab, et väärtus on väär

        int a = 0; 
        while(n>0){
            a+=pow(n%10,1); // pow abil saab funktsiooni arv astme
            n=n/10;
        }
        return isHappy(a);
    }
};
