#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 100;

vector<int> g1[N], g2[N];
int degree1[N], degree2[N];
unordered_map<int, int> labels1, labels2;
bool used1[N], used2[N];
int n, m;

bool check(int u1, int u2) {
    if (degree1[u1] != degree2[u2]) return false;
    if (labels1[u1] != labels2[u2]) return false;
    return true;
}

bool dfs(int u1, int u2) {
    used1[u1] = true;
    used2[u2] = true;
    if (!check(u1, u2)) return false;
    for (int i = 0; i < g1[u1].size(); i++) {
        int v1 = g1[u1][i];
        bool found = false;
        for (int j = 0; j < g2[u2].size(); j++) {
            int v2 = g2[u2][j];
            if (!used2[v2] && dfs(v1, v2)) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool isIsomorphic() {
    for (int i = 0; i < n; i++) {
        if (degree1[i] != degree2[i]) return false;
        labels1[i] = g1[i].size();
        labels2[i] = g2[i].size();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (degree1[i] == degree2[j] && !used1[i] && !used2[j]) {
                if (dfs(i, j)) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g1[u].push_back(v);
        degree1[u]++;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g2[u].push_back(v);
        degree2[u]++;
    }
    if (isIsomorphic()) cout << "The two graphs are isomorphic." << endl;
    else cout << "The two graphs are not isomorphic." << endl;
    return 0;
}
