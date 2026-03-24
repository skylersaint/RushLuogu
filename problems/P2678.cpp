#include <bits/stdc++.h>
#define MAX 50005
int L, N, M;
int D[MAX] = {0};
bool check(int ans)
{
    // check ans
    int remove = 0;
    int last = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        if (D[i] - last >= ans)
            last = D[i];
        else
        {
            remove++;
            if (remove > M)
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> L >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> D[i];
    }
    D[N + 1] = L;
    int left = 0, right = L;
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
