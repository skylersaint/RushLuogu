#include <bits/stdc++.h>

constexpr int MAX = 105;
constexpr int INF = 0x3f3f3f3f;
int N;
int a[MAX];
long long presum[2 * MAX];
long long dp_min[2 * MAX][2 * MAX]; // 0-min,1-max
long long dp_max[2 * MAX][2 * MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;
    std::fill(presum, presum + 2 * MAX, 0);
    // init dp
    std::fill(&dp_min[0][0], &dp_min[0][0] + 4 * MAX * MAX, INF);
    std::fill(&dp_max[0][0], &dp_max[0][0] + 4 * MAX * MAX, -1);
    // input
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        std::cin >> tmp;
        a[i] = tmp;
        presum[i] = presum[i - 1] + a[i];
        // if(i>=2){
        //     dp[0][i-1][i] = presum[i]-presum[i-2];
        //     dp[1][i-1][i] = presum[i]-presum[i-2];
        // }
        dp_min[i][i] = 0;
        dp_max[i][i] = 0;
    }
    for (int i = N + 1; i <= 2 * N; i++)
    {
        presum[i] = presum[i - 1] + a[i - N];
        dp_min[i][i] = 0;
        dp_max[i][i] = 0;
    }

    // state transition
    for (int len = 2; len <= N; len++)
    {
        for (int l = 1; l + len - 1 <= 2 * N; l++)
        {
            int r = (l + len - 1);
            for (int k = l; k < r; k++)
            {
                dp_min[l][r] = std::min(dp_min[l][r], dp_min[l][k] + dp_min[k + 1][r] + presum[r] - presum[l - 1]);
                dp_max[l][r] = std::max(dp_max[l][r], dp_max[l][k] + dp_max[k + 1][r] + presum[r] - presum[l - 1]);
            }
        }
    }
    long long min = INF;
    long long max = -1;
    for (int i = 1; i <= N; i++)
    {
        min = std::min(min, dp_min[i][i + N - 1]);
        max = std::max(max, dp_max[i][i + N - 1]);
    }
    std::cout << min << "\n"
              << max << "\n";
    return 0;
}