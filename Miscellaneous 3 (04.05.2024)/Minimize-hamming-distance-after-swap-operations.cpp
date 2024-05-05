class DSU {
    vector<int> par, rank;
    public:
    DSU(int n) {
        par.resize(n, -1);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    int findpar(int node) {
        if (node == par[node]) return node;
        return par[node] = findpar(par[node]);
    }
    bool unio(int u, int v) {
        int uu = findpar(u);
        int vv = findpar(v);
        if (uu == vv) return false;
        if (rank[uu] > rank[vv])
            par[vv] = par[uu];
        else if (rank[uu] < rank[vv])
            par[uu] = par[vv];
        else {
            par[uu] = par[vv];
            rank[vv]++;
        }
        return true;
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU d(n);
        for (auto it : allowedSwaps)
            d.unio(it[0], it[1]);
        unordered_map<int, unordered_map<int, int>> m1, m2;
        for (int i = 0; i < n; i++) {
            int u = d.findpar(i);
            m1[u][source[i]]++;
            m2[u][target[i]]++;
        }
        int result = 0;
        for (auto it : m1) {
            int ele = it.first;
            for (auto itt : it.second) {
                int value = itt.second;
                if (m2[ele][itt.first]) {
                    result += min(value, m2[ele][itt.first]);
                }
            }
        }
        return n - result;
    }
};
