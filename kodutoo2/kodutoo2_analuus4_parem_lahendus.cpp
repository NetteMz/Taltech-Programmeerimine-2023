/*
*   Viide lahendusele:
*   https://bit.ly/3lJbT1f
*
*   (Ilmselt on tegu koopiaga sellest lahedusest: https://bit.ly/3LRwATc)
*
*/

bool isPalindrome(int x){
    if(x<0 || x!=0 && x%10 ==0 ) return false;
    int check=0;
    while(x>check){
        check = check*10 + x%10;
        x/=10;
    }
    return (x==check || x==check/10);
}