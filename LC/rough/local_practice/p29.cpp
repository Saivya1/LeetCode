#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int collectApples(int N, long long P, vector<int> &Milk, vector<int> &Apples)
{
    vector<vector<long long>> dp(N + 1, vector<long long>(P + 1, -1));
    dp[0][P] = 0; // Start with initial energy P and no apples collected.

    for (int i = 1; i <= N; ++i)
    {
        for (long long energy = 0; energy <= P; ++energy)
        {
            if (dp[i - 1][energy] == -1)
                continue;

            // Option 1: Take apples from the current farm.
            if (energy >= 1)
            { // Ensure enough energy to move to the next farm.
                dp[i][energy - 1] = max(dp[i][energy - 1], dp[i - 1][energy] + Apples[i - 1]);
            }

            // Option 2: Take milk from the current farm.
            if (energy + Milk[i - 1] >= 1)
            { // Ensure enough energy to move forward.
                dp[i][min(P, energy + Milk[i - 1] - 1)] = max(dp[i][min(P, energy + Milk[i - 1] - 1)], dp[i - 1][energy]);
            }
        }
    }

    // Find the maximum apples collected across all valid states at the last farm.
    long long maxApples = 0;
    for (long long energy = 0; energy <= P; ++energy)
    {
        maxApples = max(maxApples, dp[N][energy]);
    }

    return maxApples;
}

int main()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        int N;
        long long P;
        cin >> N >> P;

        vector<int> Milk(N), Apples(N);
        for (int i = 0; i < N; ++i)
            cin >> Milk[i];
        for (int i = 0; i < N; ++i)
            cin >> Apples[i];

        cout << collectApples(N, P, Milk, Apples) << endl;
    }

    return 0;
}
