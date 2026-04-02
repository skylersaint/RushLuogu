#include <bits/stdc++.h>

const int MAXN = 1e6 + 5;
int N, M;
int h[MAXN];
long long presum[MAXN];
bool check(int H)
{
    // get tree >=M,return true;
    std::fill(presum, presum + N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        if (h[i] > H)
        {
            presum[i] = presum[i - 1] + (h[i] - H);
        }
        else
        {
            presum[i] = presum[i - 1];
        }
    }
    if (presum[N] >= M)
        return true;
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> h[i];
    }
    int left = 1;
    int right = *std::max_element(h + 1, h + N + 1);
    while (left < right)
    {
        int mid = left + (right - left + 1) / 2;
        if (check(mid))
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    std::cout << left << "\n";
    return 0;
}