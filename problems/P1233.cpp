#include <bits/stdc++.h>
#define MAX 5005

struct Stick
{
    int l = 0;
    int w = 0;
    bool operator<(const Stick &other) const
    {
        if (l != other.l)
            return l > other.l;
        return w > other.w;
    }
};
Stick sticks[MAX];
int dp[MAX];
int n;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> sticks[i].l >> sticks[i].w;
        dp[i] = 1;
    }
    std::sort(sticks + 1, sticks + n + 1);
    // std::fill(dp + 1, dp + n + 1, 1);
    int lis = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (sticks[j].w < sticks[i].w)
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        lis = std::max(lis, dp[i]);
    }
    std::cout << lis << "\n";
    return 0;
}