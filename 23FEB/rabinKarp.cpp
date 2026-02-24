#include <iostream>
using namespace std;

const int BASE = 256;
const long long MOD = 1000000007LL;

vector<int> searchPattern(string text, string pattern) {
    vector<int> result;

    int n = text.length();
    int m = pattern.length();

    if (m > n || m == 0)
        return result;

    long long patternHash = 0;
    long long windowHash = 0;
    long long power = 1;

    // Compute BASE^(m-1) % MOD
    for (int i = 0; i < m - 1; i++) {
        power = (power * BASE) % MOD;
    }

    // Compute initial hashes
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * BASE + pattern[i]) % MOD;
        windowHash = (windowHash * BASE + text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; i++) {

        // If hash matches, verify characters
        if (patternHash == windowHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i);
            }
        }

        // Update rolling hash
        if (i < n - m) {
            windowHash = (windowHash - text[i] * power) % MOD;
            windowHash = (windowHash * BASE + text[i + m]) % MOD;

            if (windowHash < 0)
                windowHash += MOD;
        }
    }

    return result;
}

int main() {
    string text = "abcabcabcadeba";
    string pattern = "cab";

    vector<int> positions = searchPattern(text, pattern);

    cout << "Pattern found at: ";
    for (int pos : positions) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}