class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<pair<int, int>> mono;
        for (int i = 0; i < n; ++i) {
            while (!mono.empty() && temperatures[i] > mono.top().first) {
                auto popped = mono.top();
                mono.pop();
                result[popped.second] = i - popped.second;
            }
            mono.push({temperatures[i], i});
        }
        return result;
    }
};
