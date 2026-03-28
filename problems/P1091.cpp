#include <bits/stdc++.h>
#define MAX 105
int n;
int l[MAX];
int r[MAX];
int ldp[MAX];
int rdp[MAX];
int lmax[MAX];
int rmax[MAX];
void getLIS(int len, int a[], int dp[], int m[])
{
    int max = INT_MIN;
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        max = std::max(max, dp[i]);
        m[i] = max;
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> l[i];
        // r[i]=l[n-i+1];
    }
    std::reverse_copy(l + 1, l + 1 + n, r + 1);
    std::fill(ldp + 1, ldp + 1 + n, 1);
    std::fill(rdp + 1, rdp + 1 + n, 1);
    getLIS(n, l, ldp, lmax);
    getLIS(n, r, rdp, rmax);
    int mincount = std::numeric_limits<int>::max();
    for (int i = 1; i <= n; i++)
    {
        int llis = lmax[i];
        int rlis = rmax[n - i];
        mincount = std::min(mincount, n - llis - rlis);
    }
    std::cout << mincount << "\n";
    return 0;
}
