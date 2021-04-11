#include <bits/stdc++.h>
using namespace std;

vector<int> F(string &p) {
    const int n = p.size();
    vector<int> f(n);
    f[0] = 0;
    for(int i = 1; i < n; i++) {
        int j = f[i - 1];
        while(p[j] != p[i] && j > 0) {
            j = f[j - 1];
        }

        if(p[i] == p[j]) {
            j++;
        }
        f[i] = j;
    }
    return f;
}

int kmp(string &p, string &t) {
    const int n = t.size();
    const int m = p.size();
    const auto &f = F(p);
    int ans = 0;
    for(int i = 0, j = 0; i < n; i++) {
        while(p[j] != t[i] && j > 0) {
            j = f[j - 1];
        }
        
        if(p[j] == t[i]) {
            j++;
        }

        if(j == m) {
            ans++;
            j = f[j - 1];
        }
    }

    return ans;
}
