class Solution {
public:
    vector<int> parent;
    int components;

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        components = n;
        for (int i = 0; i < n; ++i) parent[i] = i;
        for (auto& e : edges) unite(e[0], e[1]);
        return components;
    }
};