class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parentheses;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (char c : s) {
            if (!closeToOpen.contains(c)) {
                parentheses.push(c);
            } else {
                if (!parentheses.empty() && parentheses.top() == closeToOpen[c]) {
                    parentheses.pop();
                } else {
                    return false;
                }
            }
        }
        return parentheses.empty();
    }
};