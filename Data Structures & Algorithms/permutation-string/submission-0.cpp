class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if (l1 > l2) return false;
        vector<int> c1(26, 0);
        vector<int> c2(26, 0);
        for (int i = 0; i < l1; i++) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }
        int matches = 0;
        for (int i = 0; i < 26; ++i) if (c1[i] == c2[i]) matches++;
        int l = 0;
        for (int r = l1; r < l2; ++r, ++l) {
            if (matches == 26) return true;
            int index = s2[r] - 'a';
            c2[index]++;
            if (c1[index] == c2[index]) matches++;
            else if (c1[index] + 1 == c2[index]) matches--;
            index = s2[l] - 'a';
            c2[index]--;
            if (c1[index] == c2[index]) matches++;
            else if (c1[index] - 1 == c2[index]) matches--;
        }
        return matches == 26;
    }
};