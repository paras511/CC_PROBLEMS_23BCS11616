#include <iostream>
using namespace std;

struct Job {
    int deadline;
    int profit;
};

vector<int> jobSequencing(vector<int>& deadlines, vector<int>& profits) {
    int n = deadlines.size();
    
    vector<Job> jobList;
    for (int i = 0; i < n; i++) {
        jobList.push_back({deadlines[i], profits[i]});
    }

    // Sort jobs by deadline
    sort(jobList.begin(), jobList.end(), [](Job a, Job b) {
        return a.deadline < b.deadline;
    });

    // Min heap for profits
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int totalProfit = 0;

    for (auto& job : jobList) {
        if (minHeap.size() < job.deadline) {
            minHeap.push(job.profit);
            totalProfit += job.profit;
        }
        else if (!minHeap.empty() && minHeap.top() < job.profit) {
            totalProfit -= minHeap.top();
            minHeap.pop();
            minHeap.push(job.profit);
            totalProfit += job.profit;
        }
    }

    return { (int)minHeap.size(), totalProfit };
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<int> deadlines(n), profits(n);

    cout << "Enter deadlines:\n";
    for (int i = 0; i < n; i++) {
        cin >> deadlines[i];
    }

    cout << "Enter profits:\n";
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    vector<int> ans = jobSequencing(deadlines, profits);

    cout << "Jobs done: " << ans[0] << endl;
    cout << "Max Profit: " << ans[1] << endl;

    return 0;
}