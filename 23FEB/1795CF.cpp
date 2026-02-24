#include <iostream>
using namespace std;

void solve(int n, vector<long long>& teaAmount, vector<long long>& drinkAmount) {
    
    // Min-heap (same as Java PriorityQueue)
    priority_queue<long long, vector<long long>, greater<long long>> finishTimes;
    
    vector<long long> result(n);
    long long totalDrunkTillNow = 0;

    for (int day = 0; day < n; day++) {
        
        long long finishDay = totalDrunkTillNow + teaAmount[day];
        finishTimes.push(finishDay);

        long long todayDrink = 0;

        while (!finishTimes.empty() &&
               finishTimes.top() <= totalDrunkTillNow + drinkAmount[day]) {
            
            long long endTime = finishTimes.top();
            finishTimes.pop();

            todayDrink += (endTime - totalDrunkTillNow);
        }

        todayDrink += (long long)finishTimes.size() * drinkAmount[day];

        totalDrunkTillNow += drinkAmount[day];
        result[day] = todayDrink;
    }

    for (long long x : result) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> teaAmount(n), drinkAmount(n);

        for (int i = 0; i < n; i++) {
            cin >> teaAmount[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> drinkAmount[i];
        }

        solve(n, teaAmount, drinkAmount);
    }

    return 0;
}