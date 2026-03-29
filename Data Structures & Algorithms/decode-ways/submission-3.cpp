class Solution {
public:
    int numDecodings(string s) {
        int one = 0, two = 1, temp = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != '0') {
                temp += two;
                if (i < s.size() - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) temp += one;
            }
            one = two;
            two = temp;
            temp = 0;
        }
        return two;
    }
};