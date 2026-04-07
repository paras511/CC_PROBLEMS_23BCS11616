
#include <iostream>
using namespace std;

int dp[1 << 20][20]; 

int tsp(int mask, int pos, vector<vector<int>>& cost, int n) {

    if (mask == ((1 << n) - 1)) {
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {

        if ((mask & (1 << city)) == 0) {

            int newCost = cost[pos][city] +
                          tsp(mask | (1 << city), city, cost, n);

            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    vector<vector<int>> cost = {
        {0,10,15,20},
        {5,0,9,10},
        {6,13,0,12},
        {8,8,9,0}
    };

    int n = cost.size();

    memset(dp, -1, sizeof(dp));

    cout << "Minimum Cost: " << tsp(1, 0, cost, n);

    return 0;
}