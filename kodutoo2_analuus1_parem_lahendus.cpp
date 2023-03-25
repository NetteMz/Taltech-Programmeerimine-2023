class Solution {
public:
    void reverseString(vector<char>& s) {
    //kaks sisendit- üks on null ja teine on s
    int left = 0;
    int right = s.size() - 1;
    //array muudetakse nulliks ja salvestatakse kõik sisestatud karakterid vastupidises järjekorras üle
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;    
    }
}
};
