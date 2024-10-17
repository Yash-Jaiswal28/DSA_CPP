#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_RUNS = 101;
const int MAX_BALLS = 61;
const int MAX_WICKETS = 11;

// DP array to store probabilities
double dp[MAX_RUNS][MAX_BALLS][MAX_WICKETS];

// Function to calculate the probability
double calculateProbability(int runsNeeded, int ballsLeft, int wicketsDown, int currentScore) {
    // Base cases
    if (runsNeeded <= 0 && currentScore >= 100) {
        return 1.0;
    }

    if (ballsLeft == 0) {
        return 0.0;
    }

    if (dp[runsNeeded][ballsLeft][wicketsDown] != -1.0) {
        return dp[runsNeeded][ballsLeft][wicketsDown];
    }

    double probability = 0.0;

    // Calculate probability for each possibility
    for (int run = 0; run <= 6; ++run) {
        if (run == 5) continue; // Skip 5 runs as it represents getting out

        int newScore = currentScore + run;
        int newWicketsDown = wicketsDown + (run == 0 || run % 2 == 0);

        if (newWicketsDown <= 10) {
            if (run % 2 == 1) {
                probability += (1.0 / 6) * calculateProbability(runsNeeded - run, ballsLeft - 1, newWicketsDown, newScore);
            } else {
                probability += (1.0 / 6) * calculateProbability(runsNeeded - run, ballsLeft - 1, newWicketsDown, newScore);
            }
        }
    }

    return dp[runsNeeded][ballsLeft][wicketsDown] = probability;
}

int main() {
    // Initialize DP array
    for (int i = 0; i < MAX_RUNS; ++i) {
        for (int j = 0; j < MAX_BALLS; ++j) {
            for (int k = 0; k < MAX_WICKETS; ++k) {
                dp[i][j][k] = -1.0;
            }
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int N, b, w, x;
        cin >> N >> b >> w >> x;

        double totalProbability = calculateProbability(N, b, w, x);

        // Calculate the inverse modulo 10^9 + 7
        long long inverseMod = 1;
        for (int i = 0; i < b; ++i) {
            inverseMod = (inverseMod * 6) % MOD;
        }

        long long result = static_cast<long long>(totalProbability * inverseMod) % MOD;
        cout << result << endl;
    }

    return 0;
}
