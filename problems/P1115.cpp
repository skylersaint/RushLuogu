#include <bits/stdc++.h>

#define MAX 200005
int n;
int a[MAX];
int dp[MAX];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    // the function of state move: dp[i]=max(a[i],dp[i-1]+a[i]);
    //  the init: dp[1]=a[1];
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    dp[1] = a[1];
    std::priority_queue<int> pq;
    pq.push(dp[1]);
    for (int i = 2; i <= n; i++)
    {
        // dp[i] = std::max(pq.top(), dp[i - 1] + a[i]);
        dp[i] = std::max(a[i], dp[i - 1] + a[i]);
        pq.push(dp[i]);
    }
    std::cout << pq.top() << "\n";
    return 0;
}