#include <bits/stdc++.h>
using namespace std;

long long sumScores(string s) {
    int n = s.size();
    vector<int> Z(n, 0);

    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }

        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }

        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }

    long long result = n; // include full string
    for (int i = 1; i < n; i++) {
        result += Z[i];
    }

    return result;
}

int main() {
    string s = "babab";
    cout << sumScores(s);
    return 0;
}