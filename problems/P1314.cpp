#include <bits/stdc++.h>

const int MAXN = 2e5 + 5;
int n, m;
long long s;
struct Ore
{
    int w;
    int v;
};
Ore ores[MAXN];
struct Interval
{
    int l;
    int r;
};

Interval ivs[MAXN];
int presum_w[MAXN];
long long presum_v[MAXN];

bool check(int w, long long &reference)
{ // if compute(w)< reference return true else false
    std::fill(presum_w, presum_w + n + 1, 0);
    std::fill(presum_v, presum_v + n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (ores[i].w >= w)
        {
            presum_w[i] = presum_w[i - 1] + 1;
            presum_v[i] = presum_v[i - 1] + ores[i].v;
        }
        else
        {
            presum_w[i] = presum_w[i - 1];
            presum_v[i] = presum_v[i - 1];
        }
    }
    long long y = 0;
    for (int i = 1; i <= m; i++)
    {
        // compute checksum
        y += ((presum_w[ivs[i].r] - presum_w[ivs[i].l - 1]) * (presum_v[ivs[i].r] - presum_v[ivs[i].l - 1]));
    }
    long long diff = std::abs(s - y);
    reference = std::min(diff, reference);
    if (y < s)
    {
        return true;
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> s;
    int max = -1;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> ores[i].w >> ores[i].v;
        max = std::max(ores[i].w, max);
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> ivs[i].l >> ivs[i].r;
    }
    int left = 1;
    int right = max + 1;
    long long reference = std::abs(s);
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (check(mid, reference))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    std::cout << reference << "\n";
    return 0;
}
