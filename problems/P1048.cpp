#include <bits/stdc++.h>

#define MAX 1005
int T, M;
int t[MAX];
int m[MAX];
int dp[MAX];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::fill(dp + 1, dp + 1 + T, 0);
    std::cin >> T >> M;
    for (int i = 1; i <= M; i++)
    {
        std::cin >> t[i] >> m[i];
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = T; j >= t[i]; j--)
        {
            dp[j] = std::max(dp[j], dp[j - t[i]] + m[i]);
        }
    }

    std::cout << dp[T] << "\n";
    return 0;
}