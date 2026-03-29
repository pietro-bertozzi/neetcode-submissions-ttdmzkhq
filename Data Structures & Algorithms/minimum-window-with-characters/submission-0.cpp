class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char, int> window, goal;
        for (char c : t) goal[c]++;
        int window_done = 0, goal_todo = goal.size();
        int best_l = 0;
        int best_len = INT_MAX, l = 0;
        char c;
        for (int r = 0; r < s.length(); ++r) {
            c = s[r];
            if (goal.count(c) && ++window[c] == goal[c]) window_done++;
            while (window_done == goal_todo) {
                if ((r - l + 1) < best_len) {
                    best_len = (r - l + 1);
                    best_l = l;
                }
                if (goal.count(s[l]) && --window[s[l]] < goal[s[l]]) window_done--;
                l++;
            }
        }
        return best_len == INT_MAX ? "" : s.substr(best_l, best_len);
    }
};
