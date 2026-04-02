#include <bits/stdc++.h>
const int MAX = 1e4 + 5;
int n, k;
std::vector<int> tasks[MAX];
int dp[MAX] = {0};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int p, t;
        std::cin >> p >> t;
        tasks[p].push_back(t);
    }
    for (int i = n; i >= 1; i--)
    {
        if (tasks[i].size() == 0)
        { // no task at i minute;
            dp[i] = dp[i + 1] + 1;
        }
        else if (tasks[i].size() == 1)
        {
            dp[i] = dp[i + tasks[i][0]];
        }
        else
        {
            for (auto x : tasks[i])
            { // has tasks at i minute;
                dp[i] = std::max(dp[i], dp[i + x]);
            }
        }
    }
    std::cout << dp[1] << "\n";
    return 0;
}