#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int s, f, p;
};

bool cmp(Job a, Job b) {
    return a.f < b.f;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter jobs (start finish profit):\n";
    for (int i = 0; i < n; i++)
        cin >> jobs[i].s >> jobs[i].f >> jobs[i].p;

    sort(jobs.begin(), jobs.end(), cmp);

    vector<int> dp(n);
    dp[0] = jobs[0].p;

    for (int i = 1; i < n; i++) {
        int incl = jobs[i].p;

        for (int j = i - 1; j >= 0; j--) {
            if (jobs[j].f <= jobs[i].s) {
                incl += dp[j];
                break;
            }
        }

        dp[i] = max(incl, dp[i - 1]);
    }

    cout << "Maximum Profit: " << dp[n - 1];
}
//input 4
1 3 5
2 5 6
4 6 5
6 7 4
