#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;

    int result = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<string, int> mp;
        int duplicate = 1;

        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0) {
                duplicate++;
                continue;
            }

            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;

            string slope = to_string(dx) + "/" + to_string(dy);
            mp[slope]++;
        }

        int maxLine = 0;
        for (auto &it : mp) {
            maxLine = max(maxLine, it.second);
        }

        result = max(result, maxLine + duplicate);
    }

    return result;
}

int main() {
    vector<vector<int>> points = {{1,1}, {2,2}, {3,3}};
    cout << maxPoints(points);
}