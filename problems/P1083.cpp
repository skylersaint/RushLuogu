#include <bits/stdc++.h>

const int MAXN = 1e6 + 5;

int n, m;
int r[MAXN];
long long diff[MAXN];

struct Rent
{
    int d;
    int s;
    int t;
};

Rent rents[MAXN];

bool check(int mid)
{
    std::fill(diff, diff + n + 1, 0);
    for (int i = 1; i <= mid; i++)
    {
        diff[rents[i].s] += rents[i].d;
        diff[rents[i].t + 1] -= rents[i].d;
    }
    long long tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        // r[i] = r[i - 1] + diff[i];
        // if (r[i] < 0)
        //     return false;
        tmp += diff[i];
        if (r[i] - tmp < 0)
            return false;
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // input
    std::cin >> n >> m;
    std::fill(r, r + n + 1, 0);
    std::fill(diff, diff + n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> r[i];
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> rents[i].d >> rents[i].s >> rents[i].t;
    }
    // solve
    int left = 0;
    int right = m;
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
    // answer==left
    if (left == m)
        std::cout << "0\n";
    else
    {
        std::cout << "-1\n"
                  << left + 1 << "\n";
    }
    return 0;
}